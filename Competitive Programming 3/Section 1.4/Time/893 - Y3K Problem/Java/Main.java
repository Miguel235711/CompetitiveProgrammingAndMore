import java.util.*;

public class Main{
    static Scanner sc = new Scanner(System.in);
    public static void main(String[]args){
        int delta;
        while((delta=sc.nextInt())!=0){
            int d=sc.nextInt(),m=sc.nextInt(),y=sc.nextInt();
            GregorianCalendar gc = new GregorianCalendar(y, m - 1, d);
            gc.add(Calendar.DATE, delta);
            System.out.println(gc.get(Calendar.DATE) + " " + Integer.valueOf(gc.get(Calendar.MONTH) + 1) + " "
            + gc.get(Calendar.YEAR));
        }
    }
}