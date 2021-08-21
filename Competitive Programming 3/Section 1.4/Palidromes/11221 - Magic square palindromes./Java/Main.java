import java.util.Scanner;

public class Main {
    static Scanner scan = new Scanner(System.in);
    static int sqrtLength;
    static int specialPos(int i){
        return sqrtLength * (i%sqrtLength) + i / sqrtLength;
    }
    static boolean magicPalindrome(String s){
        for(int i1=0;i1<s.length();i1++){
            int i3 = s.length()-1-i1, i2 = specialPos(i1) , i4 = specialPos(i3);
            char c1 = s.charAt(i1);
            if(c1!=s.charAt(i2) || c1!=s.charAt(i3) || c1!=s.charAt(i4))
                return false;
        }
        return true;
    }
    public static void main(String[]args){
        int t = Integer.parseInt(scan.nextLine());
        for(int cs = 0 ; cs < t ; cs++){
            String s = scan.nextLine();
            s=s.replaceAll("[\\s\\+\\,\\.\\?\\!\\(\\)]","");
            sqrtLength = (int)Math.sqrt(s.length());
            System.out.printf("Case #%d:\n%s\n",cs+1,sqrtLength*sqrtLength==s.length()&&magicPalindrome(s)?sqrtLength:"No magic :(");
        }
    }
}