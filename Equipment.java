package Lab_9;

import java.util.Arrays;
import java.util.stream.Stream;

public class Equipment {
    Helmet [] helmets;
    Jacket [] jackets;

    public Equipment(Helmet [] helmets, Jacket [] jackets){
        this.helmets = helmets;
        this.jackets = jackets;
    }

    public double getPrice(){
        double suma = 0.0;
        for(Helmet h: helmets) suma += h.getPrice();
        for(Jacket j: jackets) suma += j.getPrice();
        return suma;
    }

    public Helmet [] sort_helmets(){
        int k = helmets.length;
        Helmet [] helmets_s = helmets;
        for (int i = 0; i<k; i++) {
            for(int j = 0; j<k-i; j++) {
                if (helmets_s[j - 1].getWeight() > helmets_s[j].getWeight()) {
                    Helmet temp = helmets_s[j - 1];
                    helmets_s[j - 1] = helmets_s[j];
                    helmets_s[j] = temp;
                }
            }
        }
        return helmets_s;
    }

        public Jacket [] sort_jackets() {
            int k = jackets.length;
            Jacket[] jackets_s = jackets;
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k - i; j++) {
                    if (jackets_s[j - 1].getWeight() > jackets_s[j].getWeight()) {
                        Jacket temp = jackets_s[j - 1];
                        jackets_s[j - 1] = jackets_s[j];
                        jackets_s[j] = temp;
                    }
                }
            }
            return jackets_s;
        }

    public void diapason(int left, int right){
        for (Helmet h: helmets) if ((h.getPrice()>=left)&&(h.getPrice()<=right)) System.out.println(h.getName());
        for (Jacket j: jackets) if ((j.getPrice()>=left)&&(j.getPrice()<=right)) System.out.println(j.getName());
    }
}
