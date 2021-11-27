package Lab_9;

public class Jacket extends Amunition{
    private int size;

    public Jacket(int size, int price, int weight, String name){
        super(price, weight, name);
        try{
            if (size < 0) throw new IllegalArgumentException();
            this.size = size;
        }
        catch (IllegalArgumentException ex)
        {
            System.out.println("Ціна не може бути від'ємною");
        }
    }

    public int getSize(){
        return size;
    }


}
