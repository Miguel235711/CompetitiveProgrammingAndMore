import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args){
        int t = s.nextInt();
        for(int cs = 1; cs <= t ; cs++){
            int maxi = 1 ; 
            for(int n = s.nextInt(); n > 0 ; n --){
                maxi = Integer.max(s.nextInt(),maxi);
            }
            System.out.printf("Case %d: %d\n",cs,maxi);
        }
    }
}