import java.util.*;

public class Main{
    static Scanner sc = new Scanner(System.in);
    static HashMap<String,Integer> monthToNumber= new HashMap<String,Integer>(){{
        put("January",1);
        put("February",2);
        put("March",3);
        put("April",4); 
        put("May",5);
        put("June",6);
        put("July",7);
        put("August",8);
        put("September",9);
        put("October",10);
        put("November",11);
        put("December",12);
    }};
    static String[] months={
        "January",
        "February", 
        "March", 
        "April", 
        "May", 
        "June",
        "July", 
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    public static void main(String[]args){
        int t = Integer.parseInt(sc.nextLine());
        for(int cs = 1 ; cs <= t ; cs++){
            String[] tks = sc.nextLine().split("-");
            int y = Integer.parseInt(tks[0]),m = monthToNumber.get(tks[1]), d = Integer.parseInt(tks[2]);
            int delta = Integer.parseInt(sc.nextLine());
            GregorianCalendar gc = new GregorianCalendar(y, m - 1, d);
            gc.add(Calendar.DATE, delta);
            System.out.printf("Case %d: %d-%s-%02d\n",cs,gc.get(Calendar.YEAR),months[gc.get(Calendar.MONTH)],gc.get(Calendar.DATE));
        }
    }
}