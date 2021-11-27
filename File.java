package Lab_9;

public class File {
    private String name;

    public File(String name){
        try{
            if (name == "") throw new IllegalArgumentException();
            this.name = name;
        }
        catch (IllegalArgumentException ex)
        {
            System.out.println("Файл не може містити пусту назву");
        }
    }

    public String getName(){
        return name;
    }

    public void changeName(String name_2){
        try{
            if (name == "") throw new IllegalArgumentException();
            this.name = name_2;
        }
        catch (IllegalArgumentException ex)
        {
            System.out.println("Файл не може містити пусту назву");
        }
    }
}
