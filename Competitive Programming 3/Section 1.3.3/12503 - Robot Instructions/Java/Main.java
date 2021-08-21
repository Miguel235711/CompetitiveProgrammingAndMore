import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    static int[] dif = new int[102];
    public static void main(String[] args){
        for(int t = Integer.parseInt(s.nextLine()); t > 0 ; t --){
            int n = Integer.parseInt(s.nextLine()),ans=0;
            for(int i = 1 ; i <= n ; i ++){
                String line = s.nextLine();
                if(line.charAt(0)=='L'){
                    dif[i]=-1;
                }else if(line.charAt(0)=='R'){
                    dif[i]=1;
                }else{
                    String[] tk = line.split(" ");
                    dif[i]=dif[Integer.parseInt(tk[2])];
                }
                ans+=dif[i];
            }
            System.out.printf("%d\n",ans);
        }
    }
}