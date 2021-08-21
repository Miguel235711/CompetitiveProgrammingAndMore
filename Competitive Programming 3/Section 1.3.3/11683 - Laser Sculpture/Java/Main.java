import java.util.Scanner;

public class Main{
    static Scanner s = new Scanner(System.in);
    public static void main(String[]args){
        int A;
        while((A=s.nextInt())!=0){
            int C = s.nextInt(),last = A,ans=0;
            for(int i = 0 ; i < C ; i++){
                int current = s.nextInt();
                if(current>last){
                    ans+=current-last;
                }
                last = current;
            }
            System.out.printf("%d\n",ans+A-last);
        }
    }
}