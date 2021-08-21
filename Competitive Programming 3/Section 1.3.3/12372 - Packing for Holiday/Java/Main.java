import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[]args){
        int t = s.nextInt();
        for(int cs = 1 ; cs <= t ; cs++){
            String ans = "good";
            for(int i = 0 ; i < 3 ; i ++){
                if(s.nextInt()>20)
                    ans="bad";
            }
            System.out.printf("Case %d: %s\n",cs,ans);
        }
    }
}