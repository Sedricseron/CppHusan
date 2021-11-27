package Lab_8;

import java.util.ArrayList;
import java.util.List;

public class Main_Task_3_7 {
    public static void main(){
        Triangle triangle_1 = new Triangle(2,3,4);
        Triangle triangle_2 = new Triangle(3.5,3.7,3.9);
        List<Triangle> list = new ArrayList<>();
        list.add(triangle_1);
        list.add(triangle_2);
        for (Triangle obj: list) {
            System.out.println("Perimeter: " + obj.getPerimeter() + ", square: " + obj.getSquare());
        }
    }
}
