import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

public class Main{
    static Scanner s = new Scanner(System.in);
    static int[] movs = {1,-1,8,-8};
    static int getInc(int Q,int newQ){
        int inc = 0;
        if((newQ-Q) % 8 == 0){
            //Q<newQ
            inc = 8;
        }else if(Q/8==newQ/8){
            inc = 1;
        }
        return inc;
    }
    static boolean colMov(int a,int b){
        return a/8==b/8;
    }
    static boolean validMov(int Q,int newQ,int K){
        if(Q>newQ){
            Q^=newQ;
            newQ^=Q;
            Q^=newQ;
        }
        int inc = getInc(Q,newQ);
        if(inc==0)
            return false;
        for(;Q<=newQ;Q+=inc){
            if(Q==K)
                return false;
        }
        return true;
    }
    static boolean reachesPlaceOfOther(int newQ,int K){
        return newQ==K-8||newQ==K+8||(colMov(K,K+1)&&newQ==K+1)||(colMov(K,K-1)&&newQ==K-1);
    }
    static boolean insideMap(int p){
        return p<64&&p>-1;
    }
    static boolean validKing(int K,ArrayList<Integer>Qpositions){
        for(int i = 0 ; i < 4 ; i ++)
            if(insideMap(K+movs[i])){
                boolean possible = true;
                for(int Qposition: Qpositions)
                    if(K+movs[i]==Qposition){
                        possible = false;
                        break;
                    }
                if(possible)
                    return true;
            }
        return false;
    }
    static String[] mapToAns = {"Illegal state","Illegal move","Move not allowed","Continue","Stop"};
    static ArrayList<Integer> getQPositions(int p){
        ArrayList<Integer>ans=new ArrayList<Integer>(Arrays.asList(p));
        for(int mov = 0 ; mov < 4 ; mov++){
            for(int newP = p + movs[mov]; (Math.abs(movs[mov])==8&&insideMap(newP))||(Math.abs(movs[mov])==1&&colMov(newP,p)); newP = newP + movs[mov]){
                ans.add(newP);
            }
        }
        return ans;
    }
    public static void main(String[]args){
        while(s.hasNextInt()){
            int K = s.nextInt(), Q = s.nextInt(), newQ = s.nextInt();
            int ans = 4; 
            if(K==Q){
                ans = 0;
            }else if(Q==newQ||!validMov(Q,newQ,K)){
                ans = 1;
            }else if(reachesPlaceOfOther(newQ,K)){
                ans = 2;
            }else if(validKing(K,getQPositions(newQ))){
                ans = 3;
            }
            System.out.printf("%s\n",mapToAns[ans]);
        }
    }
}