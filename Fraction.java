package Lab_8;

public class Fraction {
    private int numerator;
    private int denominator;

    public Fraction(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
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

    public void Skorotiti(){
        int gcd = Util.gcd(numerator, denominator);
        this.numerator /= gcd;
        this.denominator /= gcd;
    }

    @Override
    public String toString(){
        return "{Fraction: " + numerator + "/" + denominator + "}";
    }
}
