import java.util.Scanner;

public class Main{
    static Scanner s = new Scanner(System.in);
    static int[] reserve = new int[22]; 
    public static void main(String[] args){
        while(true){
            int B = s.nextInt(), N  = s.nextInt();
            if(B==0&&N==0)
                return;
            for(int i = 1 ; i <= B ; i ++){
                reserve[i] = s.nextInt();
            }
            for(int i = 1 ; i <= N ; i ++){
                int a = s.nextInt(), b = s.nextInt(), c = s.nextInt() ; 
                reserve[a]-=c;
                reserve[b]+=c;
            }
            char ans = 'S';
            for(int i = 1 ; i <= B ; i ++){
                if(reserve[i]<0){
                    ans = 'N';
                    break;
                }
            }
            System.out.printf("%c\n",ans);
        }
    }
}