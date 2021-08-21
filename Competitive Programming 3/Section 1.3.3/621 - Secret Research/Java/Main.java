import java.util.Scanner;

public class Main{
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args){
        for(int n = Integer.parseInt(s.nextLine()); n > 0 ; n --){
            String line = s.nextLine();
            char ans ='?';
            if(line.compareTo("1")==0||line.compareTo("4")==0||line.compareTo("78")==0){
                ans='+';
            }else if(line.charAt(line.length()-2)=='3'&&line.charAt(line.length()-1)=='5'){
                ans='-';
            }else if(line.charAt(0)=='9'&&line.charAt(line.length()-1)=='4'){
                ans='*';
            }
            System.out.printf("%c\n",ans);
        }
    }
}