import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        for(int cs = 1;;cs++){
            int ans = 0 ;
            for(int n = s.nextInt(); n > 0 ; n --){
                int x = s.nextInt();
                ans += x==0 ? -1 : 1;
            }
            if(!s.hasNextInt())
                return;
            System.out.printf("Case %d: %d\n",cs,ans);
        }  
    }
}