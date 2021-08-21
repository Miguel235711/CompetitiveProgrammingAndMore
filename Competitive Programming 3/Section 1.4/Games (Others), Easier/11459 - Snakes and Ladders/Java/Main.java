import java.util.Scanner;
import java.util.Arrays;

public class Main {
    static Scanner s = new Scanner(System.in);
    static void printAns(int[]players){
        for(int i=0;i<players.length;i++)
            System.out.printf("Position of player %d is %d.\n",i+1,players[i]+1);
    }
    public static void main(String[]args){
        for(int t=s.nextInt();t>0;t--){
            int a=s.nextInt(),b=s.nextInt(),c=s.nextInt();
            int[] players=new int[a],go=new int[100];
            Arrays.fill(go,-1);
            for(int i=0;i<b;i++){
                int orig=s.nextInt(),dest=s.nextInt();
                go[orig-1]=dest-1;
            }
            boolean won=false;
            for(int times=0,player=0;times<c;times++){
                int val = s.nextInt();
                if(!won){
                    players[player]=Math.min(players[player]+val,99);
                    if(go[players[player]]!=-1)
                        players[player]=go[players[player]];
                    if(players[player]==99){
                        won=true;
                        printAns(players);
                    }
                    player=(player+1)%a;
                }
            }
            if(!won)
                printAns(players);
        }
    }
}