import java.util.Scanner;

public class Main{
    static int extraDiv(int a,int b){
        return a%b>0? 1 : 0 ;
    }
    static int operation(int a){
        a-=2;
        //System.out.printf("a/3= %d\n",a/3);
        return a/3 + extraDiv(a,3);
    }
    public static void main(String[]args){
        Scanner s = new Scanner(System.in);
        for(int t = s.nextInt(); t > 0 ; t --){
            int n = s.nextInt(), m = s.nextInt();
            System.out.printf("%d\n",operation(n) * operation(m));
        }
    }
}