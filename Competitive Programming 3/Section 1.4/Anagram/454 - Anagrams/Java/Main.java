import java.util.Scanner;
import java.util.Collections;
import java.util.Vector;
import java.util.Arrays;

public class Main{
    public static Scanner s = new Scanner(System.in);
    static class pair implements Comparable<pair> {
        public String phrase;
        public String sorted;
        public pair(String phrase){
            this.phrase=phrase;
        }
        @Override
        public int compareTo(pair o){
            return phrase.compareTo(o.phrase);
        }
    }
    public static void main(String[] args){
        int n = Integer.parseInt(s.nextLine());
        s.nextLine();
        for(int cs=0;cs<n;cs++){
            if(cs!=0)
                System.out.println();
            String line;
            Vector<pair> pairs = new Vector<pair>();
            while(s.hasNextLine()&&!(line=s.nextLine()).isEmpty())
                pairs.add(new pair(line));
            Collections.sort(pairs);
            //sort individual chars
            for(int i = 0 ; i < pairs.size(); i ++){
                pair refX = pairs.get(i);
                char[] sortedArray = refX.phrase.replaceAll(" ","").toCharArray();
                Arrays.sort(sortedArray);
                refX.sorted = new String(sortedArray);
            }
            //brute force
            for(int i = 0 ; i < pairs.size(); i ++){
                for(int j = i + 1 ; j < pairs.size(); j ++){
                    pair refI = pairs.get(i),refJ = pairs.get(j);
                    if(refI.sorted.equals(refJ.sorted))
                        System.out.printf("%s = %s\n",refI.phrase,refJ.phrase);
                }
            }
        }
    }
}