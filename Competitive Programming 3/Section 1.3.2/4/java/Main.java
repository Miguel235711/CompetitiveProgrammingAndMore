import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int a,b,cs=0;
        while (s.hasNextInt()) {
            a = s.nextInt();
            b = s.nextInt();
            System.out.printf("Case %d: %d\n",++cs,a+b);
            if(s.hasNextInt()){
                System.out.print("\n");
            }
        }
    }
}