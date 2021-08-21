import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args){
        String line ; 
        for(int cs = 1;;cs++){
            String ans = "Akbar";
            line = s.next();
            if(line.charAt(0)=='U'){
                ans = "Asghar";
            }else if(line.charAt(0)=='*'){
                break;
            }
            System.out.printf("Case %d: %s\n",cs,"Hajj-e-"+ans);
        }
    }
}