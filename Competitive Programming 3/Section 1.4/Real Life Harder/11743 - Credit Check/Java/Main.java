import java.util.*;

public class Main{
    static int digitSum(int x){
        int sum=0;
        for(;x!=0;x/=10)
            sum+=x%10;
        return sum;
    }
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args){
        for(int n = Integer.parseInt(sc.nextLine()); n > 0 ; n --){
            int sum = 0 ;
            String x = sc.nextLine();
            for(int i = 0 , c = 0 ; i < x.length() ; i ++){
                char xi = x.charAt(i);
                if(xi!=' '){
                    if((c&1)==1)
                        sum+=xi-'0';
                    else
                        sum+=digitSum((xi-'0')<<1);
                    c++;
                }
            }
            System.out.println(sum%10==0?"Valid":"Invalid");
        }
    }
}