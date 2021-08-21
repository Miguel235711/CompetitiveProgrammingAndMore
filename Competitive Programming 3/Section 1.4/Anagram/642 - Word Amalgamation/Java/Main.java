import java.util.Scanner;
import java.util.HashMap;
import java.util.Vector;
import java.util.Arrays;
import java.util.Map;
import java.util.Collections;

public class Main{
    static Scanner sc = new Scanner(System.in);
    static HashMap<String,Vector<String>> anagrams = new HashMap<String,Vector<String>>();
    public static void main(String[]args){
        String line;
        while((line=sc.next()).charAt(0)!='X'){
            char[] lineC = line.toCharArray();
            Arrays.sort(lineC);
            String sortedLine = new String(lineC);
            if(anagrams.containsKey(sortedLine))
                anagrams.get(sortedLine).add(line);
            else{
                final String lineCp = line;
                anagrams.put(sortedLine,new Vector<String>(){
                    {
                        add(lineCp);
                    }
                });
            }
        }
        //sort Vectors
        anagrams.forEach((k,v) -> Collections.sort(v));
        //answer anagram queries
        while((line=sc.next()).charAt(0)!='X'){
            char[] lineC = line.toCharArray();
            Arrays.sort(lineC);
            line = new String(lineC);
            if(anagrams.containsKey(line))
                for(String element: anagrams.get(line))
                    System.out.println(element);
            else
                System.out.println("NOT A VALID WORD");
            System.out.println("******");
        }
    }
}