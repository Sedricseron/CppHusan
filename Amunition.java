package Lab_9;

public class Amunition {
    private int price;
    private int weight;
    private String name;

    public Amunition(){
        this.price = 0;
        this.weight = 0;
        this.name = "";
    }

    public Amunition(int price, int weight, String name){
        try{
            if (price < 0) throw new IllegalArgumentException();
            this.price = price;
        }
        catch (IllegalArgumentException ex)
        {
            System.out.println("Ціна не може бути від'ємною");
        }
        try{
            if (price < 0) throw new IllegalArgumentException();
            this.weight = weight;
        }
        catch (IllegalArgumentException ex)
        {
            System.out.println("Вага не може бути від'ємною");
        }
        this.name = name;
    }


    public int getPrice(){
        return price;
    }

    public int getWeight(){
        return weight;
    }

    public String getName(){
        return name;
    }
}
