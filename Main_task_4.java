package Lab_13;

import java.io.*;
import java.util.Random;
import java.util.Scanner;

public class Main_task_4 {
    public static void main(String[] args) {
        random_numbers();
        separation_func();
    }

    public static void random_numbers() {
        Random random = new Random();
        System.out.print("Input n: ");
        Scanner sc_n = new Scanner(System.in);
        int n = sc_n.nextInt();
        System.out.print("Input filename: ");
        Scanner sc_fn = new Scanner(System.in);
        String filename = sc_fn.next();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = random.nextInt();
        }
        writeBinaryFile(filename, array);
    }

    public static void separation_func() {
        System.out.print("Input filename to read: ");
        Scanner sc_fn = new Scanner(System.in);
        String file_read = sc_fn.next();
        System.out.print("Input first filename to write: ");
        Scanner sc_wn_1 = new Scanner(System.in);
        String file_write_1 = sc_wn_1.next();
        System.out.print("Input second filename to write: ");
        Scanner sc_wn_2 = new Scanner(System.in);
        String file_write_2 = sc_wn_2.next();
        int[] start_file = readBinaryFile(file_read);
        assert start_file != null;
        int cnt_even = 0;
        for (int i = 0; i < start_file.length; i++) {
            if (start_file[i] % 2 == 0) {
                cnt_even++;
            }
        }
        int[] even = new int[cnt_even];
        int[] odd = new int[start_file.length - cnt_even];
        int i_even = 0, i_odd = 0;
        for (int i = 0; i < start_file.length; i++) {
            if (start_file[i] % 2 == 0) {
                even[i_even] = start_file[i];
                i_even++;
            }
            else
            {
                odd[i_odd] = start_file[i];
                i_odd++;
            }
        }
        writeBinaryFile(file_write_1, even);
        writeBinaryFile(file_write_2, odd);
    }

    public static void writeBinaryFile(String filename, int[] array) {
        FileOutputStream fos;
        BufferedOutputStream bos;
        DataOutputStream dos;

        try {
            fos = new FileOutputStream(filename);
            bos = new BufferedOutputStream(fos);
            dos = new DataOutputStream(bos);

            for (int n : array)
                dos.writeInt(n);

            dos.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static int[] readBinaryFile(String filename) {
        FileInputStream fis;
        BufferedInputStream bis;
        DataInputStream dis;

        try {
            fis = new FileInputStream(filename);
            bis = new BufferedInputStream(fis);
            dis = new DataInputStream(bis);

            File file = new File(filename);
            long size = file.length();
            int count = (int) size / Integer.BYTES;
            int[] array = new int[count];
            for (int i = 0; i < count; i++)
                array[i] = dis.readInt();

            dis.close();
            return array;

        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }
}
