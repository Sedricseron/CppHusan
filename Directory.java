package Lab_9;

public class Directory {
    private String name;

    public Directory(String name){
        try{
            if (name == "") throw new IllegalArgumentException();
            this.name = name;
        }
        catch (IllegalArgumentException ex)
        {
            System.out.println("Директорія не може містити пусту назву");
        }
    }

    public String getName(){
        return name;
    }
}
