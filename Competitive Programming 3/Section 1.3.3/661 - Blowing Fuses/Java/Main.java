import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    static boolean[] isTurnedOn;
    static int[] consumption = new int[22];
    public static void main(String[] args){
        int cs=1;
        while(true){
            int n=s.nextInt(),m=s.nextInt(),c=s.nextInt();
            if(n==0&&m==0&&c==0)
                break;
            System.out.printf("Sequence %d\n",cs++);
            isTurnedOn = new boolean[22];
            for(int i = 1 ; i <= n ; i ++){
                consumption[i]=s.nextInt();
            }
            int toggleI,consumed=0,maxConsumed=0;
            for(int i = 0 ; i < m ; i ++){
                toggleI = s.nextInt();
                if(isTurnedOn[toggleI]==true){
                    consumed-=consumption[toggleI];
                }else{
                    consumed+=consumption[toggleI];
                }
                isTurnedOn[toggleI]=!isTurnedOn[toggleI];
                maxConsumed=Math.max(maxConsumed,consumed);
            }
            System.out.printf("Fuse was %s.\n",maxConsumed>c?"blown":"not blown");
            if(maxConsumed<=c){
                System.out.printf("Maximal power consumption was %d amperes.\n",maxConsumed);
            }
            System.out.printf("\n");
        }
    }
}