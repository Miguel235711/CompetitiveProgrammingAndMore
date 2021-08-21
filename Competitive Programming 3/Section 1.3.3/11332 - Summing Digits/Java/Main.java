import java.util.Scanner;

public class Main{
    static Scanner s = new Scanner(System.in);

    static int sumDigits(int x){
        int ans = 0;
        for(;x>0;x/=10)
            ans+=x%10;
        return ans;
    }
    public static void main(String[] args){
        while(true){
            int n = s.nextInt();
            if(n!=0){
                while(n>9){
                    n = sumDigits(n);
                }
                System.out.printf("%d\n",n);
            }else{
                break;
            }
        }
    }
}  