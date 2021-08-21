import java.util.Scanner;
import java.util.HashMap;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;

public class Main{
    static Scanner sc = new Scanner(System.in);
    static HashMap<String,Integer> sortedLowerStrings = new HashMap<String,Integer>();
    static ArrayList<Boolean> anagram = new ArrayList<Boolean>();
    static ArrayList<String> original = new ArrayList<String>();
    static ArrayList<String> output = new ArrayList<String>();
    public static void main(String[]args){
        String word;
        while((word=sc.next()).charAt(0)!='#'){
            if(!word.isEmpty()){
                anagram.add(false);
                original.add(word);
                char[] wordChars = word.toLowerCase().toCharArray();
                Arrays.sort(wordChars);
                word = new String(wordChars);
                if(sortedLowerStrings.containsKey(word)){
                    //visit both
                    anagram.set(sortedLowerStrings.get(word),true);
                    anagram.set(anagram.size()-1,true);
                }else
                    sortedLowerStrings.put(word,anagram.size()-1);
            }
        }
        for(int i = 0 ; i < original.size() ; i ++)
            if(!anagram.get(i))
                output.add(original.get(i));
        Collections.sort(output);
        for(String wordP : output)
            System.out.printf("%s\n",wordP);
    }
}