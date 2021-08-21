import java.util.Scanner;

public class Main{
    public static void main(String[]args){
        Scanner s = new Scanner(System.in);
        for(int t = s.nextInt(); t > 0 ; t --){
            int n = s.nextInt();
            System.out.printf("%d\n",Math.abs((n*63+7492)*5-498) / 10 % 10);
        }
    }
}