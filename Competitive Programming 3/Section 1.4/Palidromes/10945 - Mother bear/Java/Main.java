import java.util.Scanner;
import java.util.HashSet;

public class Main{
    static Scanner scan = new Scanner(System.in);  
    static HashSet<Character> puntuaction = new HashSet<Character>(){{
        add('.');
        add(',');
        add('!');
        add('?');
        add(' ');
    }};

    static boolean palindrome(String s){
        for(int i = 0 , j = s.length()-1 ; i < j ; i ++ , j --){
            //ignore puntuactions
            for(;i<j&&puntuaction.contains(s.charAt(i));i++);
            for(;i<j&&puntuaction.contains(s.charAt(j));j--);
            //check if equivalent (ignoring casing)
            if(i<j&&Character.toLowerCase(s.charAt(i))!=Character.toLowerCase(s.charAt(j)))
                return false;
        }
        return true;
    }
    public static void main(String[] args){
        String s;
        while(!(s=scan.nextLine()).equals("DONE")){
            System.out.printf("%s\n",palindrome(s)?"You won't be eaten!":"Uh oh..");
        }
    }
}