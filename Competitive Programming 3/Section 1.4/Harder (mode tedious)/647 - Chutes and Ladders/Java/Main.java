import java.util.Scanner;
import java.util.ArrayList;

public class Main{
    static Scanner s = new Scanner(System.in);
    static enum sp{
        none,
        lose,
        extra
    }
    public static void main(String[] args){
        ArrayList<Integer> thrS = new ArrayList<Integer>();
        int x;
        while((x=s.nextInt())!=0){
            thrS.add(x);
        }
        int n;
        while((n=s.nextInt())!=0){
            //init game set
            int[] jumpTo = new int [101];
            for(int i=1;i<101;i++)
                jumpTo[i]=i;
            sp[] special = new sp[101];
            //read game set
            while(true){
                int a=s.nextInt(),b=s.nextInt();
                if(a==0)
                    break;
                jumpTo[a]=b;
            }
            while((x=s.nextInt())!=0){
                int absX = Math.abs(x);
                special[absX]= x < 0 ? sp.lose : sp.extra;
            }
            //simulate
            boolean[] loseTurn = new boolean[n];
            int[] cell = new int[n];
            for(int throwI=0,player=0;;throwI++,player=(player+1)%n){
                if(loseTurn[player])
                    loseTurn[player]=false;
                else{    
                    int dieNewCell = cell[player]+thrS.get(throwI);
                    if(dieNewCell<101){
                        cell[player]=jumpTo[dieNewCell];
                        if(special[cell[player]]==sp.lose)
                            loseTurn[player]=true;
                        else if(special[cell[player]]==sp.extra){
                            player--;
                            if(player<0)
                                player=n-1;
                        }
                        if(cell[player]==100){
                            System.out.println(player+1);
                            break;
                        }
                    }
                } 
            }
        }
    }
}