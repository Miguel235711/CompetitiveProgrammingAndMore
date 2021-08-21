import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int a,b;
        while (s.hasNextInt()) {
            a = s.nextInt();
            b = s.nextInt();
            System.out.printf("%d\n",a+b);
        }
    }
}