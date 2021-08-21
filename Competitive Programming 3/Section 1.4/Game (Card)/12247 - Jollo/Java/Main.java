import java.util.Scanner;
import java.util.Arrays;

public class Main{
    static Scanner s = new Scanner(System.in);
    static int[] princess = new int[3], prince = new int[2];
    static boolean[] defeatedMe,taken;
    public static void main(String[]args){
        while(true){
            taken = new boolean[52];
            defeatedMe = new boolean[3];
            princess[0] = s.nextInt();
            if(princess[0]==0)
                return;
            taken[princess[0]-1]=true;
            for(int i = 1 ; i < 3 ; i ++){
                princess[i] = s.nextInt();
                taken[princess[i]-1]=true;
            }
            Arrays.sort(princess);
            int index = 0,lost=0 ;
            for(int i = 0; i < 2 ; i ++){
                prince[i] = s.nextInt();
                taken[prince[i]-1]=true;
            }
            Arrays.sort(prince);
            for(int i = 0 ; i < 2 ; i ++){
                for(;index<3&&princess[index]<prince[i];index++);
                if(index<3){
                    defeatedMe[index]=true;
                    index++;
                    lost++;
                }
            }
            int ans=-1;
            if(lost==0){
                //smallest not taken card
                for(int i = 0; i < 52 ; i ++){
                    if(!taken[i]){
                        ans = i + 1;
                        break;
                    }
                }
            }else if(lost==1){
                //greatest one to defeat
                for(int i = 2 ; i > -1 ; i --){
                    if(!defeatedMe[i]){
                        ans = princess[i]+1;
                        for(;ans<=52&&taken[ans-1];ans++);
                        if(ans>52)
                            ans=-1;
                        break;
                    }
                }
            }   
            System.out.printf("%d\n",ans);
        }
    }
}