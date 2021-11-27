package Lab_9;

public class Helmet extends  Amunition{
    private int type_of_protection;

    public Helmet(int type_of_protection, int price, int weight, String name){
        super(price, weight, name);
        try{
            if (type_of_protection < 0) throw new IllegalArgumentException();
            this.type_of_protection = type_of_protection;
        }
        catch (IllegalArgumentException ex)
        {
            System.out.println("Ступінь захисту не може бути від'ємною");
        }
    }

    public int getType_of_protection(){
        return type_of_protection;
    }
}
