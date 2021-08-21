import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args){
        int t = Integer.parseInt(s.nextLine());
        for(int cs = 0 ; cs < t ; cs++){
            s.nextLine();
            if(cs>0)
                System.out.println();
            int n = Integer.parseInt(s.nextLine());
            String [] tk = s.nextLine().split(" ");
            int dif = Integer.parseInt(tk[0]) - Integer.parseInt(tk[1]);
            String ans = "yes";
            for(int i = 1 ; i < n ; i ++){
                tk = s.nextLine().split(" ");
                if(Integer.parseInt(tk[0]) - Integer.parseInt(tk[1])!=dif){
                    ans = "no";
                }
            }
            System.out.println(ans);
        }
    }
}