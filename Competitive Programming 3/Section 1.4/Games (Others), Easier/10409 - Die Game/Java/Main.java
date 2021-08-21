import java.util.Scanner;
import java.util.HashMap;

public class Main{
    static class Pair{
        public int group,dif;
        public Pair(int group,int dif){
            this.group=group;
            this.dif=dif;
        }
    }
    static Scanner s = new Scanner(System.in);
    static int[] aux = new int[4];
    static HashMap<String,Pair> mapMov = new HashMap<String,Pair>(){{
        put("south",new Pair(0,-1));
        put("north",new Pair(0,1));
        put("east",new Pair(1,-1));
        put("west",new Pair(1,1));
    }};
    static int minusOne(int i){
        if(i==0)
            return 3;
        return i-1;
    }
    static int plusOne(int i){
        return (i+1)%4;
    }
    static int One(int i,int dif){
        if(dif==1)
            return plusOne(i);
        return minusOne(i);
    }
    public static void main(String[]args){
        while(true){
            int n = Integer.parseInt(s.nextLine());
            if(n==0)
                return;
            int[][] groups = {{6,2,1,5},{6,3,1,4}};// 0 and 2 need to be copied each time
            for(;n>0;n--){
                Pair com = mapMov.get(s.nextLine());
                for(int i=0;i<4;i++)
                    aux[i]=groups[com.group][One(i,com.dif)];
                System.arraycopy(aux,0,groups[com.group],0,aux.length);
                groups[1-com.group][0]=groups[com.group][0];
                groups[1-com.group][2]=groups[com.group][2];
            }
            System.out.printf("%d\n",groups[0][2]);
        }
    }
}