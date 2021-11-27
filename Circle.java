package Lab_8;

public class Circle {
    private Fraction x;
    private Fraction y;
    private double r;

    public Circle(Fraction x, Fraction y, double r) {
        this.x = x;
        this.y = y;
        this.r = r;
    }

    public double getSquare() {
        return 3.14*r*r;
    }

    public double getPerimeter() {
        return 2.0*3.14*r;
    }
}
