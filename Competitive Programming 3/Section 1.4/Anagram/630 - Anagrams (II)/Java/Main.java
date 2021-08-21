import java.util.Scanner; 
import java.util.HashMap;
import java.util.Vector;
import java.util.Arrays;
import java.util.Collection;

public class Main{
    static Scanner sc = new Scanner(System.in);
    public static void main(String[]args){
        int t = Integer.parseInt(sc.nextLine());
        for(int cs=0;cs<t;cs++){
            HashMap<String,Vector<String>> anagrams = new HashMap<String,Vector<String>>();
            if(cs!=0)
                System.out.println();
            sc.nextLine();
            String line;
            for(int n = Integer.parseInt(sc.nextLine());n>0;n--){
                line = sc.nextLine();
                char[] lineC = line.toCharArray();
                Arrays.sort(lineC);
                String sortedLine = new String(lineC);
                final String copyLine = line;
                if(!anagrams.containsKey(sortedLine))
                    anagrams.put(sortedLine,new Vector<String>(){
                        {
                            add(copyLine);
                        }
                    });
                else
                    anagrams.get(sortedLine).add(line);
            }
            //anagrams queries
            while(!(line=sc.nextLine()).equals("END")){
                String original = line;
                System.out.printf("Anagrams for: %s\n",original);
                char[] originalC = original.toCharArray();
                Arrays.sort(originalC);
                line = new String(originalC);
                if(anagrams.containsKey(line)){
                    Vector<String> vectorRef = anagrams.get(line);
                    for(int i=0;i<vectorRef.size();i++)
                        System.out.printf("%s) %s\n",String.format("%3d",i+1),vectorRef.get(i));
                }
                else  
                    System.out.printf("No anagrams for: %s\n",original);
            }
        }
    }
}