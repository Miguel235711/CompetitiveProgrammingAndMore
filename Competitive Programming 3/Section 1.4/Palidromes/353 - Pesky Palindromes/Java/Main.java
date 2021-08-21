import java.util.Scanner;
import java.util.HashSet;

public class Main{
    static Scanner s = new Scanner(System.in);
    static boolean isPalindrome(String s){
        int lim = s.length()>>1;
        for(int i=0;i<lim;i++)
            if(s.charAt(i)!=s.charAt(s.length()-i-1))
                return false;
        return true;
    }
    public static void main(String[]args){
        while(s.hasNextLine()){
            String line = s.nextLine();
            HashSet<String> differentPs = new HashSet<String>();
            for(int i=0;i<line.length();i++){
                for(int j=i;j<line.length();j++){
                    String substring = line.substring(i,j+1);
                    if(isPalindrome(substring))
                        differentPs.add(substring);
                }
            }
            System.out.printf("The string '%s' contains %d palindromes.\n",line,differentPs.size());
        }
    }
}