import java.util.*;

public class Main{
    static Scanner sc = new Scanner(System.in);
    public static void main(String[]args){
        int t = sc.nextInt();
        for(int cs = 1 ; cs <= t ; cs++){
            int C = sc.nextInt(), d = sc.nextInt();
            System.out.printf("Case %d: %.2f\n",cs,C+5.0*d/9);
        }
    }
}