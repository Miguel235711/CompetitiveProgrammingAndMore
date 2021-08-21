import java.util.Scanner;

public class Main {

    static int difPositions(int orig,int dest, boolean clockwise){
        if(clockwise){
            //swap orig = A , dest = B
            orig^=dest;  // A ->B, B -> A
            dest^=orig;
            orig^=dest;
        }
        return dest < orig ? orig-dest : 40 - dest + orig;
    }

    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        while(true){
            int init = s.nextInt(), a = s.nextInt(), b = s.nextInt(), c = s.nextInt();
            if(init==0&&a==0&&b==0&&c==0){
                break;
            }
            System.out.printf("%d\n",(difPositions(init,a,false) + difPositions(a,b,true) + difPositions(b,c,false)) * 9 + 1080);
        }
    }
}