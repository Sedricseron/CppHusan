package Lab_9;

import java.util.Scanner;

public class Main_task_32 {
    public static void main() {
        Scanner in = new Scanner(System.in);
        String text = in.next();
        int shift = in.nextInt();
        char[] chars = text.toCharArray();
        for (int i=0; i < text.length(); i++)
        {
            char c = chars[i];
            if (c >= 32 && c <= 127)
            {
                int x = c - 32;
                x = (x + shift) % 96;
                if (x < 0)
                    x += 96;
                chars[i] = (char) (x + 32);
            }
        }
        System.out.println(new String(chars));
    }
}
