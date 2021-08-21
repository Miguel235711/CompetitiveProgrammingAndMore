import java.util.Scanner;
import java.util.Arrays;

public class Main{
    static Scanner s = new Scanner(System.in);
    static final int lim=90;
    static boolean[]possible=new boolean[lim];// for [0] -> 1, [1] -> 2 
    static int[]arr=new int[lim+1];
    public static void main(String[]args){
        while(true){
            int N=s.nextInt(),B=s.nextInt();
            if(N==0)
                return;
            for(int i=0;i<B;i++){
                arr[i]=s.nextInt();
            }
            Arrays.fill(possible,false);
            int remain=N;
            for(int i=0;i<B;i++){
                for(int j=i+1;j<B;j++){
                    if(!possible[Math.abs(arr[i]-arr[j])-1]){
                        possible[Math.abs(arr[i]-arr[j])-1]=true;
                        remain--;
                    }
                }
            }
            System.out.printf("%c\n",remain==0?'Y':'N');
        }
    }
}