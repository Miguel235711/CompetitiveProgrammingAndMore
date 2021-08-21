import java.util.Scanner;

public class Main{
    static Scanner s = new Scanner(System.in);
    static boolean[] taken;
    public static void main(String[]args){
        while(true){
            int k = s.nextInt();
            if(k==0)
                break;
            int m = s.nextInt();
            taken=new boolean[10000];
            for(int i = 0 ; i < k ; i ++){
                taken[s.nextInt()]=true;
            }   
            boolean isYes = true;         
            for(int i = 0 ; i < m ; i ++){
                int c=s.nextInt(),r=s.nextInt();
                for(int j = 0 ; j < c ; j ++){
                    if(taken[s.nextInt()]){
                        r--;
                    }
                }
                if(r>0)
                    isYes=false;
            }
            System.out.printf("%s\n",isYes?"yes":"no");
        }
    }
}