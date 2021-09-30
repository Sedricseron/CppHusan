package com.company;
import java.util.Scanner;

public class Task_4_1_d {
    public static double Computation(float x){
        double res = (4*x + 1);
        double sqr = res*res;
        return (sqr*sqr);
    }
    public static void Task_4_1_d() {
        Scanner in = new Scanner(System.in);
        float a = in.nextFloat();
        System.out.print(Computation(a));
    }
}
