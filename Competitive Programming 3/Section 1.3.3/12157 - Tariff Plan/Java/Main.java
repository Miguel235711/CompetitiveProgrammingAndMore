import java.util.Scanner;

public class Main{
    static Scanner s = new Scanner(System.in); 
    public static void main(String[] args){
        int t = s.nextInt();
        for(int cs = 1 ; cs <= t ; cs++){
            int mCost = 0 , jCost = 0 ; 
            for(int n = s.nextInt(); n > 0 ; n -- ) {
                int time = s.nextInt();
                mCost += (time / 30+1) * 10;
                jCost += (time / 60+1) * 15;
                //System.out.println("time: "+time+"Juice cost "+jCost+" mileCost "+mCost);
            }
            String ans = "Juice "+jCost;
            if(mCost<jCost){
                ans = "Mile "+mCost;
            }else if(mCost==jCost){
                ans = "Mile Juice "+mCost;
            }
            System.out.printf("Case %d: %s\n",cs,ans);
        }
    }
}