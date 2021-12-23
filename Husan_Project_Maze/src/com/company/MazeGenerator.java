package com.company;

import java.awt.*;
import java.awt.event.*;
import java.awt.geom.Path2D;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
import javax.swing.*;

/**
 * Генерація рандомного лабіринту розміру 24 на 24 з пошуком найкоротшого виходу з довільної точки
 * Проєкт виконав студент 3-го курсу комп. мат. 1 Гусан Дмитро, 21.12.2021
 */
public class MazeGenerator extends JPanel {
    enum Dir {
        N(1, 0, -1), S(2, 0, 1), E(4, 1, 0), W(8, -1, 0);
        final int bit;
        final int dx;
        final int dy;
        Dir opposite;


        static {
            N.opposite = S;
            S.opposite = N;
            E.opposite = W;
            W.opposite = E;
        }

        Dir(int bit, int dx, int dy) {
            this.bit = bit;
            this.dx = dx;
            this.dy = dy;
        }
    };
    final int nCols;
    final int nRows;
    final int cellSize = 25;
    final int margin = 25;
    final int[][] maze;
    int start_c;
    int start_r;
    LinkedList<Integer> solution;

    /**
     * генерує лабіринт
     * @param size розмір лабіринту, сам лабіринт є квадратним
     * @param start_c координата стовпця початкової точки
     * @param start_r координата рядка початкової точки
     */
    public MazeGenerator(int size, int start_c, int start_r) {
        this.start_c = start_c;
        this.start_r = start_r;
        setPreferredSize(new Dimension(650, 650));
        setBackground(Color.white);
        nCols = size;
        nRows = size;
        maze = new int[nRows][nCols];
        solution = new LinkedList<>();
        generateMaze(0, 0);

        addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                new Thread(() -> {
                    solve(start_c  + start_r * nRows);
                }).start();
            }
        });
    }

    /**
     * Малює сам лабіринт в окремому вікні та показує процес пошуку вихожу в реальному часі
     * @param gg графічний компонент
     */
    @Override
    public void paintComponent(Graphics gg) {
        super.paintComponent(gg);
        Graphics2D g = (Graphics2D) gg;
        g.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);

        g.setStroke(new BasicStroke(5));
        g.setColor(Color.black);

        // малює лабіринт
        for (int r = 0; r < nRows; r++) {
            for (int c = 0; c < nCols; c++) {

                int x = margin + c * cellSize;
                int y = margin + r * cellSize;

                if ((maze[r][c] & 1) == 0) // N
                    g.drawLine(x, y, x + cellSize, y);

                if ((maze[r][c] & 2) == 0) // S
                    g.drawLine(x, y + cellSize, x + cellSize, y + cellSize);

                if ((maze[r][c] & 4) == 0) // E
                    g.drawLine(x + cellSize, y, x + cellSize, y + cellSize);

                if ((maze[r][c] & 8) == 0) // W
                    g.drawLine(x, y, x, y + cellSize);
            }
        }

        // малює анімацію пошуку виходу
        int offset = margin + cellSize / 2;

        Path2D path = new Path2D.Float();
        path.moveTo((start_c + start_r * nRows) % nCols * cellSize + offset , (start_c  + start_r * nRows) / nCols * cellSize + offset);
        for (int pos : solution) {
            int x = pos % nCols * cellSize + offset;
            int y = pos / nCols * cellSize + offset;
            path.lineTo(x, y);
        }
        g.setColor(Color.orange);
        g.draw(path);

        g.setColor(Color.blue);
        g.fillOval((start_c + start_r * nRows) % nCols * cellSize + offset , (start_c  + start_r * nRows) / nCols * cellSize + offset,  10, 10);

        g.setColor(Color.green);
        int x = offset + (nCols - 1) * cellSize;
        int y = offset + (nRows - 1) * cellSize;
        g.fillOval(x - 5, y - 5, 10, 10);

    }

    /**
     * Генерація рандомного лабіринту
     * @param r початкова координата рядка точки генерації
     * @param c початкова координата стовпця точки генерації
     */
    void generateMaze(int r, int c) {
        Dir[] dirs = Dir.values();
        Collections.shuffle(Arrays.asList(dirs));
        for (Dir dir : dirs) {
            int nc = c + dir.dx;
            int nr = r + dir.dy;
            if (withinBounds(nr, nc) && maze[nr][nc] == 0) {
                maze[r][c] |= dir.bit;
                maze[nr][nc] |= dir.opposite.bit;
                generateMaze(nr, nc);
            }
        }
    }

    /**
     * Перевірка перетину стін лабіринту
     * @param r координата рядка точки
     * @param c координата стовпця точки
     * @return 1 - якщо не перетинає, 0 - якщо перетинає
     */
    boolean withinBounds(int r, int c) {
        return c >= 0 && c < nCols && r >= 0 && r < nRows;
    }

    /**
     * Побудова виходу з лабіринту
     * @param pos позиція - число, яке рахується як номер рядка помножений на їх кількість плюс номер стовпця
     * @return true - якщо вихід існує, false - якщо ні
     */
    boolean solve(int pos) {
        if (pos == nCols * nRows - 1)
            return true;

        int c = pos % nCols;
        int r = pos / nCols;

        for (Dir dir : Dir.values()) {
            int nc = c + dir.dx;
            int nr = r + dir.dy;
            if (withinBounds(nr, nc) && (maze[r][c] & dir.bit) != 0
                    && (maze[nr][nc] & 16) == 0) {

                int newPos = nr * nCols + nc;

                solution.add(newPos);
                maze[nr][nc] |= 16;

                animate();

                if (solve(newPos))
                    return true;

                animate();

                solution.removeLast();
                maze[nr][nc] &= ~16;
            }
        }

        return false;
    }

    /**
     * Анімація пошуку виходу з лабіринту в реальному часі
     */
    void animate() {
        try {
            Thread.sleep(50L);
        } catch (InterruptedException ignored) {
        }
        repaint();
    }

    public static void main() throws IOException {
        System.out.println("1 - запит з консолі, 2 - запит з файла");
        Scanner in = new Scanner(System.in);
        int i = Integer.parseInt(in.nextLine());
        int start_c, start_r;
        if (i==1){
            System.out.println("У лабіринті 24 на 24 введіть точку, з якої треба вибратися. Введіть номер колоки від 0 до 24");
            start_c = in.nextInt();
            System.out.println("Введіть номер рядка від 0 до 24");
            start_r = in.nextInt();
        }
        else{
            System.out.println("Введіть абсолютний шлях до файлу: ");
            String path = in.nextLine();

            BufferedReader br = new BufferedReader(new FileReader(path));
            int[] values = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(Integer::valueOf).toArray();
            start_c = values[0];
            start_r = values[1];
        }
        SwingUtilities.invokeLater(() -> {
            JFrame f = new JFrame();
            f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            f.setTitle("Maze Generator");
            f.setResizable(false);
            if ((start_c<0)||(start_c>24)||(start_r<0)||(start_r>24)) {
                System.out.println("Значення координат знаходяться в межах від 0 до 24");
                System.exit(0);
            }
            f.add(new MazeGenerator(24, start_c, start_r), BorderLayout.CENTER);
            f.pack();
            f.setLocationRelativeTo(null);
            f.setVisible(true);
        });
    }
}

