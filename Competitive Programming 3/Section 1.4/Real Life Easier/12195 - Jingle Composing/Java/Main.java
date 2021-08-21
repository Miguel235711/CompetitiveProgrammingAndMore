import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static HashMap<Character,Double> durations = new HashMap<Character,Double>(){{
        put('W',1.0);
        put('H',0.5);
        put('Q',0.25);
        put('E',0.125);
        put('S',0.0625);
        put('T',0.03125);
        put('X',0.015625);
    }};
    static boolean isRight(String s){
        double sum = 0 ;
        for(int i = 0 ; i < s.length(); i++){
            sum+=durations.get(s.charAt(i));
        }
        return sum==1;
    }
    public static void main(String[]args){
        String s;
        while((s=sc.nextLine()).charAt(0)!='*'){
            int ans=0;
            for(String meassure: s.split("/")){
                if(!meassure.isEmpty()&isRight(meassure))
                    ans++;
            }
            System.out.printf("%d\n",ans);
        }
    }
}