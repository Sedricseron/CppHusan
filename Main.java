package com.company;

import java.util.Scanner;
import java.util.*;


public class Main {

    public static void task_3_11(){
        Scanner in = new Scanner(System.in);
        int [] array = new int[16]; // x[1], x[2], ..., y[1], ..., y[8] x1y1 - x4y4 - first rectangle
        for(int i=0; i<16; i++){
            array[i] = in.nextInt();
        }
        int xL = Math.max(array[0], array[4]); //max(x1,x5)
        int xR = Math.min(array[1], array[5]); //min(x2,x6)
        if (xR <= xL)
            System.out.print("no intersection");
        else{
            int yT = Math.max(array[8],array[12]); //max(y1, y5)
            int yB = Math.min(array[9],array[13]); //min(y2, y6) - YBottom
            if (yB <= yT)
                System.out.print("no intersection");
            else{
                System.out.println(xL + yB + (xR-xL)  + (yB-yT));
            }
        }
    }

    public static void task_4_16(){
        Scanner in = new Scanner(System.in);
        int month = in.nextInt();
        int day = in.nextInt();
        int year = in.nextInt();
        String [] array = {"січень","лютий","березень","квітень","травень","червень","липень","серпень","вересень","жовтень","листопад","грудень"};
        if (1<=month&&month<=12){
            if (month == 2){
                if (year % 4 == 0){
                    if (1<=day&&day<=29) {
                        System.out.print(day + " лютий " + year);
                        System.exit(1);
                    }
                    else System.out.print("error");
                    }
                else{
                    if (1<=day&&day<=28) {
                        System.out.print(day + " лютий " + year);
                        System.exit(1);
                    }
                    else System.out.print("error");
                }
            }
            if (month == 1||month == 3||month == 5||month == 7||month == 8||month == 10||month == 12){
                if (1<=day&&day<=31){
                    System.out.print(day + array[month-1] + year);
                }
                    else System.out.print("error");
                }
            else{
                if (1<=day&&day<=30){
                    System.out.print(day + array[month-1] + year);
                }
                    else System.out.print("error");
            }
        }
    }

    public static void task_1_11(){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        float sum_x = 0;
        float sum_y = 0;
        float sum_m = 0;
        for(int i = 0; i<n; i++){
            String line = in.next();
            String [] line2 = line.split(",");
            float [] line3 = new float[3];
            for(int j=0; j<3;j++){
                line3[j] = Float.parseFloat(line2[i].toString());
            }
            sum_x += line3[0];
            sum_y += line3[1];
            sum_m += line3[2];
        }
        System.out.print((sum_x/n) + "," + (sum_y/n) + "," + (sum_m/n));
    }

    public static void task_1_23(){
        Scanner in = new Scanner(System.in);
        System.out.print("Enter first 9 digit numbers: ");
        int[] arr = new int[9];
        int checkSum = 0;
        String line = in.next();
        String [] line2 = new String[9];
        line2 = line.split("");
        for (int i = 0 ; i < 9; i++)
        {
            arr[i] = Integer.parseInt(line2[i].toString());
            checkSum = (arr[i] * i) % 11;
        }
        System.out.print("The ISBN-10 Number is " );
        for(int j = 0 ; j < 9; j++)
        {
            System.out.print(arr[j]);
        }

        if(checkSum == 10)
        {
            System.out.println("x");
        }
        else
        {
            System.out.println(checkSum);
        }
    }

    public static void task_2_11(){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[][] a = new int[n][n];
        int[][] b = new int[n][n];
        int[][] c = new int[n][n];
        System.out.println("enter the matrix");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = in.nextInt();
            }
        }
        System.out.println("input matrix");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
        int sumRow = 0, x = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sumRow += a[i][j];
            }
            if (sumRow != 0) {
                for (int k = 0; k < n; k++) {
                    b[i - x][k] = a[i][k];
                }
            } else {
                x++;
            }
            sumRow = 0;
        }
        int sumCol = 0, y = 0, temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - x; j++) {
                sumCol += b[j][i];
            }
            if (sumCol != 0) {
                for (int k = 0; k < n - x; k++) {
                    if (temp == 0) {
                        c[k][i] = b[k][i];
                    }
                    if (temp == 1 && n > 3) {
                        c[k][i] = b[k][i + 1];
                    }
                }
            } else {
                for (int k = 0; k < n - x; k++) {
                    c[k][i] = b[k][i + 1];
                    temp = 1;
                }
            }
            sumCol = 0;
        }
        System.out.println("outut matix:");
        for (int i = 0; i < n - x; i++) {
            for (int j = 0; j < n - y - temp; j++) {
                System.out.print(c[i][j] + " ");
            }
            System.out.println();
        }
    }

    static int LIP(int dp[][], int mat[][], int n, int x, int y)
    {
        if (dp[x][y] < 0) {
            int result = 0;

            if (x == n - 1 && y == n - 1)
                return dp[x][y] = 1;

            if (x == n - 1 || y == n - 1)
                result = 1;

            if (x + 1 < n && mat[x][y] < mat[x + 1][y])
                result = 1 + LIP(dp, mat, n, x + 1, y);

            if (y + 1 < n && mat[x][y] < mat[x][y + 1])
                result = Math.max(result, 1 + LIP(dp, mat, n, x, y + 1));

            dp[x][y] = result;
        }

        return dp[x][y];
    }

    static int wrapper(int mat[][], int n)
    {
        int dp[][] = new int[n][n];
        for (int i = 0; i < n; i++)
            Arrays.fill(dp[i], -1);

        return LIP(dp, mat, n, 0, 0);
    }
    static int calc(int A[][], int i, int j) {
        int n = A.length;
        int r=1;   // only this element forms a single element sequence
        int res = 1;
        if (j<n) if(A[i][j]>A[i][j+1]) r=Math.max(r, 1+ calc(A, i, j+1));
        if (j>0) if((A[i][j]>A[i][j-1])) r=Math.max(r, 1+ calc(A, i, j-1));
        if (i<n) if(A[i][j]>A[i+1][j]) r=Math.max(r, 1+ calc(A, i+1, j));
        if (i>0) if((A[i][j]>A[i-1][j])) r=Math.max(r, 1+ calc(A, i-1, j));
        res=Math.max(res,r);
        return r;
    }
    public static void task_2_3(){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int [][] a = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = in.nextInt();
            }
        }
        System.out.println(wrapper(a, n)); //increase
        System.out.println(calc(a, 0, 0)); // decrease
    }

    public static void main(String[] args) {
        task_3_11();
        task_4_16();
        task_1_11();
        task_1_23();
        task_2_11();
        task_2_3();
    }


}