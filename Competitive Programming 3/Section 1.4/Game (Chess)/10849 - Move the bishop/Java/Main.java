import java.util.Scanner;

public class Main{
    static Scanner s = new Scanner(System.in);
    static int getColor(int i,int j,int n){
        long cell = n * i + j;
        if((n&1)==1||(i&1)==0)
            return (int)cell&1;
        return 1 - (int)(cell&1);
    }
    static boolean sameCross(int i,int j,int iO,int jO){
        return Math.abs(iO-i)==Math.abs(jO-j);
    }
    public static void main(String[]args){
        for(int c = s.nextInt();c>0;c--){
            int t = s.nextInt(),n = s.nextInt();
            for(;t>0;t--){
                int i = s.nextInt()-1,j=s.nextInt()-1,iO=s.nextInt()-1,jO=s.nextInt()-1;
                String ans = "no move";
                if(getColor(i,j,n)==getColor(iO,jO,n)){
                    if(i==iO&&j==jO)
                        ans="0";
                    else if(sameCross(i,j,iO,jO))
                        ans = "1";
                    else
                        ans = "2";
                }
                System.out.printf("%s\n",ans);
            }
        }
    }
}