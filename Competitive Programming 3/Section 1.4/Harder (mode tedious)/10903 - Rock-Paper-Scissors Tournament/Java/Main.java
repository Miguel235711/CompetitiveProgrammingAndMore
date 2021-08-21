import java.util.Scanner;
import java.util.Arrays;
import java.util.HashMap;

public class Main{
    static Scanner s = new Scanner(System.in);
    static int[] wins = new int[101], loses = new int [101];
    static int n,k;
    static HashMap<String,String> winsOver = new HashMap<String,String>(){{
        put("scissors","paper");
        put("paper","rock");
        put("rock","scissors");
    }}; 
    static void init(){
        Arrays.fill(wins,1,n+1,0);
        Arrays.fill(loses,1,n+1,0);
    }
    public static void main(String[]args){
        for(int cs=0;(n=s.nextInt())!=0;cs++){
            if(cs!=0)
                System.out.printf("\n");
            init();
            k=s.nextInt();
            int totalGames=k*n*(n-1)/2;
            for(int game = 0 ; game < totalGames ; game++){
                int p1=s.nextInt();
                String move1 = s.next();
                int p2=s.nextInt();
                String move2 = s.next();
                //int a, int b 
                if(winsOver.get(move1).equals(move2)){
                    wins[p1]++;
                    loses[p2]++;
                }else if(winsOver.get(move2).equals(move1)==0){
                    wins[p2]++;
                    loses[p1]++;
                }
            }
            for(int i=1;i<=n;i++)
                if(wins[i]+loses[i]!=0)
                    System.out.printf("%.3f\n",(float)wins[i]/(wins[i]+loses[i]));
                else
                    System.out.printf("-\n");
        }
    }
}