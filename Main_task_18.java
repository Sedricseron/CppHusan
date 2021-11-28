package Lab_9;

import java.util.Scanner;

public class Main_task_18 {
    static boolean valid_identifier(String my_str, int n){
        if (!((my_str.charAt(0) >= 'a' && my_str.charAt(0) <= 'z')
                || (my_str.charAt(0)>= 'A' && my_str.charAt(1) <= 'Z')
                || my_str.charAt(0) == '_'))
            return false;
        for (int i = 1; i < my_str.length(); i++){
            if (!((my_str.charAt(i) >= 'a' && my_str.charAt(i) <= 'z')
                    || (my_str.charAt(i) >= 'A' && my_str.charAt(i) <= 'Z')
                    || (my_str.charAt(i) >= '0' && my_str.charAt(i) <= '9')
                    || my_str.charAt(i) == '_'))
                return false;
        }
        return true;
    }
    public static void main(){
        Scanner in = new Scanner(System.in);
        String text = in.next();
        int n = text.length();
        if (valid_identifier(text, n))
            System.out.println("It is valid");
        else
            System.out.println("It is invalid");
    }
}
