import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args){
        while(true){
            int a = s.nextInt(),b = s.nextInt();
            if(a==-1)
                break;
            if(b>a){
                a^=b;
                b^=a;
                a^=b;
            }
            System.out.printf("%d\n",Math.min(a-b,100-a+b));
        }
    }
}