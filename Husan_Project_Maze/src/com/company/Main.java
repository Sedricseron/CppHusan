package com.company;

import java.io.IOException;

public class Main {

    public static void main(String[] args) {
        try {
            MazeGenerator.main();
        } catch (IOException e) {System.out.println(e.getMessage());}
    }
}
