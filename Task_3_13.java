package com.company;
import java.util.Scanner;

public class Task_3_13 {
    public static void Task_3_13() {
        float a;
        Scanner in = new Scanner(System.in);
        a = in.nextFloat();
        double b = Math.pow(a, 8);
        String formattedDouble = String.format("%.4f", b);
        System.out.print(formattedDouble);
    }
}
