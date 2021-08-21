import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        Scanner s = new Scanner(System.in);
        for(int t = s.nextInt() ; t > 0 ; t --){
            int n = s.nextInt(), minimum = 99 , maximum = 0 ;
            for(int i = 0 ; i < n ; i ++){
                int x = s.nextInt();
                minimum = Integer.min(minimum,x);
                maximum = Integer.max(maximum,x);
            }
            System.out.printf("%d\n",maximum-minimum+maximum-minimum);
        }
    }
}