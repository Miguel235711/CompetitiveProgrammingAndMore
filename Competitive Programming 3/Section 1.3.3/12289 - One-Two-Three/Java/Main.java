import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args){
        for(int n = Integer.parseInt(s.nextLine()); n > 0 ; n --){
            String line = s.nextLine();
            int ans = 2;
            if(line.length()==5){
                ans=3;
            }else if(((line.charAt(0)=='o'||line.charAt(1)=='n')&&line.charAt(2)=='e')||(line.charAt(0)=='o'&&line.charAt(1)=='n')){
                ans=1;
            }
            System.out.printf("%d\n",ans);
        }
    }
}