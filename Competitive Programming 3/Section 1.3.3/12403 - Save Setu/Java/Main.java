import java.util.Scanner;

public class Main{
    static Scanner s = new Scanner(System.in);
    static int k = 0 ;
    public static void main(String[] args){
        for(int t = s.nextInt(); t > 0 ; t --){
            String command = s.next();
            if(command.charAt(0)=='d'){
                k+=s.nextInt();
            }else{
                System.out.printf("%d\n",k);
            }
        }
    }
}