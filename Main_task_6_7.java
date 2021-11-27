package Lab_9;

public class Main_task_6_7 {
    public static void main(){
        Helmet h1 = new Helmet(6, 14, 20, "helmet 1");
        Helmet h2 = new Helmet(5, 50, 15, "helmet 2");
        Jacket j1 = new Jacket(20, 47, 14, "jacket 1");
        Jacket j2 = new Jacket(17,35,10,"jacket 2");
        Helmet [] helmets = new Helmet[]{h1, h2};
        Jacket [] jackets = new Jacket[]{j1, j2};
        Equipment equip = new Equipment(helmets, jackets);
        System.out.println(equip.getPrice());
        System.out.println(equip.sort_helmets());
        System.out.println(equip.sort_jackets());
        equip.diapason(12, 30);
    }
}
