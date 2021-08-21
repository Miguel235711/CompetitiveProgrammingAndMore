import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        Scanner s = new Scanner(System.in);
        for(int t = s.nextInt(); t > 0 ; t--){
            int a = s.nextInt(), b = s.nextInt();
            System.out.printf("%c\n",a<b?'<':(a==b?'=':'>'));
        }
    }
}