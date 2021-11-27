package Lab_8;

import java.util.ArrayList;
import java.util.List;

public class Main_task_4_6 {
    public static void main() {
        double max_p = 0.0;
        double max_s = 0.0;
        Circle c1 = new Circle(new Fraction(2, 5), new Fraction(1, 3), 4.0);
        Circle c2 = new Circle(new Fraction(3, 7), new Fraction(8, 9), 3.0);
        Circle c3 = new Circle(new Fraction(4, 7), new Fraction(5, 9), 6.0);
        List<Circle> list = new ArrayList<>();
        list.add(c1);
        list.add(c2);
        for (Circle obj : list) {
            if (obj.getPerimeter() > max_p) max_p = obj.getPerimeter();
            if (obj.getSquare() > max_s) max_s = obj.getSquare();
        }
        System.out.print(max_s+"\n");
        System.out.print(max_p);
    }
}
