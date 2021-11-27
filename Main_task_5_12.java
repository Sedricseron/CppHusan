package Lab_9;

public class Main_task_5_12 {
    public static void main(){
        TextFile txtfile = new TextFile(new File("Name"), new Directory("Directory"));
        txtfile.rename("Name2");
        System.out.println(txtfile.getName());
        txtfile.add_text("qwrty");
        System.out.println(txtfile.get_text());
    }
}
