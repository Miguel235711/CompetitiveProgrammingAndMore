import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[]args){
        char type;
        for(int t = s.nextInt();t>0;t--){
            type = s.next().charAt(0);
            int n=s.nextInt(),m=s.nextInt(),maxAns=0;
            if(type=='r'){
                maxAns=Math.min(m,n);
            }else if(type=='k'){
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
                    maxAns = (n*m+1)/2;
                }
            }else if(type=='Q'){
                maxAns = m == n && (n==2||m==3) ? n-1 : Math.min(m,n);
            }else{
                maxAns = (int)Math.ceil((float)m/2)*(int)Math.ceil((float)n/2);
            }
            System.out.printf("%d\n",maxAns);
        }
    }
}