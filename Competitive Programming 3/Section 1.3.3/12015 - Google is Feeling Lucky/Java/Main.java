import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class Main{
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args){
        int t = Integer.parseInt(s.nextLine());
        for(int cs=1; cs<=t ;cs++){
            Queue<String> pages = new LinkedList<>();
            String page;
            int maximum = 0 ;
            for(int i = 0 ; i < 10 ; i ++){
                String[] tk = s.nextLine().split(" ");
                int vi = Integer.parseInt(tk[1]);
                if(maximum<vi){
                    maximum = vi;
                    pages.clear();
                }
                if(maximum == vi){
                    pages.add(tk[0]);
                }
            }
            System.out.printf("Case #%d:\n",cs);
            while(pages.isEmpty()==false){
                System.out.printf("%s\n",pages.remove());
            }
        }
    }
}