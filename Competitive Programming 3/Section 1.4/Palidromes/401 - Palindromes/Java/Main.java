import java.util.Scanner;
import java.util.HashMap;

public class Main{
    static Scanner scan = new Scanner(System.in);
    static String[][] ans = {{"is not a palindrome","is a mirrored string"},{"is a regular palindrome","is a mirrored palindrome"}};
    static HashMap<Character,Character> reversed = new HashMap<Character,Character>(){{
        put('A','A');
        put('E','3');
        put('H','H');
        put('I','I');
        put('J','L');
        put('L','J');
        put('M','M');
        put('O','O');
        put('S','2');
        put('T','T');
        put('U','U');
        put('V','V');
        put('W','W');
        put('X','X');
        put('Y','Y');
        put('Z','5');
        put('1','1');
        put('2','S');
        put('3','E');
        put('5','Z');
        put('8','8');
    }};
    static int getPalindromeValue(String s){
        int lim = s.length()>>1;
        for(int i = 0 ; i < lim ; i ++)
            if(s.charAt(i)!=s.charAt(s.length()-1-i))
                return 0;
        return 1;
    }
    static String getMirroredString(String s){
        char[] sArray = s.toCharArray();
        for(int i=0;i<sArray.length;i++){
            if(reversed.containsKey(sArray[i]))
                sArray[i]=reversed.get(sArray[i]);
            else
                return null;
        }
        return new String(sArray);
    }
    static int getMirroredPalindromeValue(String s){
        String mirroredString = getMirroredString(s);
        if(mirroredString==null)
            return 0;
        //compared if mirroredString backwards is the same as s
        for(int i=0;i<s.length();i++)
            if(s.charAt(i)!=mirroredString.charAt(s.length()-1-i))
                return 0;
        return 1;
    }
    public static void main(String[]args){
        while(scan.hasNextLine()){
            String s = scan.nextLine();
            int isPalindrome = getPalindromeValue(s), isMirrored = getMirroredPalindromeValue(s);
            System.out.printf("%s -- %s.\n\n",s,ans[isPalindrome][isMirrored]);
        }
    }
}