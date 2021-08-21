import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[]args){
        int x1;
        while((x1=s.nextInt())!=0){
            int y1=s.nextInt(),x2=s.nextInt(),y2=s.nextInt();
            System.out.printf("%c\n",x1==x2&&y1==y2?'0':(x1==x2 || y1==y2 || Math.abs(x2-x1)==Math.abs(y2-y1)?'1':'2'));
        }
    }
}