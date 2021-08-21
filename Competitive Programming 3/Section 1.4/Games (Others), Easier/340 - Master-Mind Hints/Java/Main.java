import java.util.Scanner;
import java.util.HashMap;

public class Main{
    static Scanner sc = new Scanner(System.in);
    static int[] s = new int[1000],g = new int[1000];
    public static void main(String[]args){
        int N;
        for(int cs = 1;(N=sc.nextInt())>0;cs++){
            System.out.printf("Game %d:\n",cs);
            for(int i = 0 ; i < N ; i ++)
                s[i] = sc.nextInt();
            while((g[0]=sc.nextInt())>0){
                int strong=0,weak=0;
                HashMap<Integer,Integer> numbersInS = new HashMap<Integer,Integer>();
                for(int i = 1 ; i < N ; i ++)
                    g[i] = sc.nextInt();
                for(int i = 0 ; i < N ; i ++)
                    if(s[i]==g[i])
                        strong++;
                    else
                        if(numbersInS.containsKey(s[i]))
                            numbersInS.replace(s[i],numbersInS.get(s[i])+1);
                        else
                            numbersInS.put(s[i],1);
                for(int i = 0; i < N ; i++)
                    if(s[i]!=g[i]&&numbersInS.containsKey(g[i])){
                        weak++;     
                        if(numbersInS.get(g[i])==1){
                            numbersInS.remove(g[i]);
                        }else{
                            numbersInS.replace(g[i],numbersInS.get(g[i])-1);
                        }
                    }
                System.out.printf("    (%d,%d)\n",strong,weak);
            }
            for(int i = 1 ; i < N ; i ++)
                sc.nextInt();
        }
    }
}