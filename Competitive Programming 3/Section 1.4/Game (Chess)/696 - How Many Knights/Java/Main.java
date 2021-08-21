import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in); 
    public static void main(String[]args){
        int n,m;
        while((n=s.nextInt())!=0){
            m=s.nextInt();
            int maxAns=0;
            if(n==1||m==1){
                maxAns = Math.max(n,m);
            }else if (n==2 || m ==2){
                int l = Math.max(n,m);
                int localAns = 0;
                localAns = (l+1)/4;
                localAns*=2;
                if(l%4==1 || l%4==2){
                    localAns += l%4;
                }
                maxAns = localAns*2;
            }else{
                maxAns = ((n*m)+1)/2;
            }
            System.out.printf("%d knights may be placed on a %d row %d column board.\n",maxAns,n,m);
        }
    }
}