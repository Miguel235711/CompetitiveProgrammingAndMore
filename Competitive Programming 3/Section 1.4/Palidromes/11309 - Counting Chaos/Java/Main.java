import java.util.Scanner;

public class Main{
    static Scanner sc = new Scanner(System.in);
    static String[] nextPal = new String [1440];
    static int toInteger(int h,int m){
        return h*60 + m;
    }
    static String toSingleString(int x){
        return String.format("%02d",x);
    }
    static String toString(int h,int m){
        return toSingleString(h)+toSingleString(m);
    }
    static String toFString(int h,int m){
        return  toSingleString(h)+":"+ toSingleString(m);
    }
    static boolean isPalindrome(int h,int m){
        String s = toString(h,m);
        if(s.charAt(0)=='0')
            s = s.replaceFirst("0+","");
        for(int i=0; i < s.length();i++)
            if(s.charAt(i)!=s.charAt(s.length()-1-i))
                return false;
        return true;
    }
    public static void main(String[]args){
        String nextP = "00:00";
        for(int h = 23 ; h > -1 ; h --){
            for (int m = 59 ; m > -1 ; m --){
                nextPal[toInteger(h,m)]=nextP;
                if(isPalindrome(h,m))
                    nextP=toFString(h,m);
            }
        }
        for(int t = sc.nextInt(); t > 0 ; t --){
            String time = sc.next();
            int h=Integer.parseInt(time.substring(0,2)),m=Integer.parseInt(time.substring(3,5));
            System.out.printf("%s\n",nextPal[toInteger(h,m)]);
        }
    }
}