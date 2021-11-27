package Lab_8;

public class Triangle {
    private double a;
    private double b;
    private double c;

    public Triangle(double a, double b, double c) {
        try{
            if ((a <= 0)||(b<=0)||(c<=0)||((a+b)<=c)||((b+c)<a)||((a+c)<b)) throw new IllegalArgumentException();
            this.a = a;
            this.b = b;
            this.c = c;
        }
        catch (IllegalArgumentException ex)
        {
            System.out.println("Сторона не може бути від'ємною або нерівність трикутника не виконується");
        }

    }

    public double getSquare() {
        double p = (a+b+c)/2;
        return Math.sqrt(p*(p-a)*(p-b)*(p-c));
    }

    public double getPerimeter() {
        return a + b + c;
    }
}
