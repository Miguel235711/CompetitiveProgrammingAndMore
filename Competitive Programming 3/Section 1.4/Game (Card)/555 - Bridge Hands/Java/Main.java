import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Collections;
import java.util.List;

public class Main {
    static Scanner s = new Scanner(System.in);
    static HashMap<Character,Integer> mapFromDirToInt = new HashMap<Character,Integer>(){{
        put('S',0);
        put('W',1);
        put('N',2);
        put('E',3);
    }};
    static HashMap<Character,Integer> mapFromSuitToInt = new HashMap<Character,Integer>(){{
        put('C',0);
        put('D',1);
        put('S',2);
        put('H',3);
    }};
    static HashMap<Character,Integer> rankToInt = new HashMap<Character,Integer>(){{
        put('T',8);
        put('J',9);
        put('Q',10);
        put('K',11);
        put('A',12);
    }};
    static char[] mapFromIntToSuit={'S','W','N','E'};
    static ArrayList<String>[] personCards;
    static int offsetChar(char x){
        if(Character.isDigit(x)){
            return x - '2';
        }
        return rankToInt.get(x);
    }
    static int toIndex(String card){
        return mapFromSuitToInt.get(card.charAt(0))*13 + offsetChar(card.charAt(1));
    }
    static class CustomComparator implements Comparator<String> {
        @Override
        public int compare(String o1, String o2) {
            return toIndex(o1)-toIndex(o2);
        }
    }
    static void initialize(){
        personCards = new ArrayList[4];
        for(int i = 0 ; i < 4 ; i++){
            personCards[i] = new ArrayList<String>();
        }
    }
    private static String[] splitToNChar(String text, int size) {
        List<String> parts = new ArrayList<>();

        int length = text.length();
        for (int i = 0; i < length; i += size) {
            parts.add(text.substring(i, Math.min(length, i + size)));
        }
        return parts.toArray(new String[0]);
    }
    public static void main(String[]args){
        while(true){
            initialize();
            String[] line = s.nextLine().split(" ");
            if(line[0].compareTo("#")==0){
                break;
            }
            for(int person=(mapFromDirToInt.get(line[0].charAt(0))+1)%4,lC=0;lC<2;lC++){
                line = splitToNChar(s.nextLine(),2);
                for(int i = 0 ; i < line.length; i++,person=(person+1)%4){
                    personCards[person].add(line[i]);
                }
            }
            for(int i = 0 ; i < 4 ; i ++){
                personCards[i].sort(new CustomComparator());
                System.out.printf("%c:",mapFromIntToSuit[i]);
                for(String card: personCards[i]){
                    System.out.printf(" %s",card);
                }
                System.out.printf("\n");
            }
        }        
    }
}