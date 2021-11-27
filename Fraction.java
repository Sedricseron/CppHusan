package Lab_8;

public class Fraction {
    private int numerator;
    private int denominator;

    public Fraction(int numerator, int denominator) {
        try{
            if (numerator == 0) throw new IllegalArgumentException();
            this.numerator = numerator;
        }
        catch (IllegalArgumentException ex)
        {
            System.out.println("чисельник не може бути нульовим");
        }
        try{
            if (denominator <= 0) throw new IllegalArgumentException();
            this.denominator = denominator;
        }
        catch (IllegalArgumentException ex)
        {
            System.out.println("знаменник не може бути від'ємною");
        }
    }

    public int getNumerator() {
        return numerator;
    }

    public int getDenominator() {
        return denominator;
    }

    public void setNumerator(int numerator) {
        this.numerator = numerator;
    }

    public void setDenominator(int denominator) {
        this.denominator = denominator;
    }


    @Override
    public String toString(){
        return "{Fraction: " + numerator + "/" + denominator + "}";
    }
}
