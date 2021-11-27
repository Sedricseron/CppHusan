package Lab_8;

public class Connection {
    String message = "No message";

    public Connection(){
    }

    public Connection(String s){
        this.message = s;
    }

    void show(){
        System.out.println("connectoin message: " + message);
    }
}
