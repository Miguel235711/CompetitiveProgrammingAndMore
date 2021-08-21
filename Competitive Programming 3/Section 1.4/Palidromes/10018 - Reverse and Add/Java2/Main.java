import java.util.Scanner;

public class Main {
    static Scanner scan = new Scanner(System.in);

    static boolean isPalindrome(String s){
        int lim = s.length() >> 1 ;
        for(int i=0;i<lim;i++)
            if(s.charAt(i)!=s.charAt(s.length()-1-i))
                return false;
        return true;
    }
    static String reverseAndAdd(String s){
        return Integer.toUnsignedString(Integer.parseUnsignedInt(s)+Integer.parseUnsignedInt(new StringBuilder(s).reverse().toString()));   
    }
    public static void main(String[]args){
        for(int cs = scan.nextInt(); cs > 0 ; cs --){
            String s = scan.next();
            int ite=0;
            for(;!isPalindrome(s);ite++)
                s = reverseAndAdd(s);
            System.out.printf("%d %s\n",ite,s);
        }
    }
}