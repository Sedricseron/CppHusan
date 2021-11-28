package Lab_9;

import javax.imageio.IIOException;
import java.io.*;

public class Main_task_6 {
    public static void main() throws IIOException {
        try (BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\User\\IdeaProjects\\untitled\\src\\Lab_9\\F"))) {
            String line;
            BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\Users\\User\\IdeaProjects\\untitled\\src\\Lab_9\\G"));
            while ((line = br.readLine()) != null) {
                writer.write(" "+line+"\n");
            }
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
