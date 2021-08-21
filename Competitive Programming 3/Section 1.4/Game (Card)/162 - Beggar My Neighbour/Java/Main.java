import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

public class Main {
    static Scanner s = new Scanner(System.in);
    static List<Queue<Integer>> personQueue = new LinkedList<Queue<Integer>>();
    static HashMap<Character,Integer> mapToInteger = new HashMap<Character,Integer>(){{
        put('A',4);
        put('J',1);
        put('Q',2);
        put('K',3);
    }};
    static int convert(String x){
        char c = x.charAt(1);
        if(Character.isDigit(c)){
            return 0;
        }
        return mapToInteger.get(c);
    }
    static void initialize(){
        for(int i = 0 ; i < 2 ; i ++){
            personQueue.add(new LinkedList<Integer>());
        }
    }
    public static void main(String[]args){
        initialize();
        Object q[] = personQueue.toArray();
        q[0].add(3);
        //personQueue.toArray()[0].add(3);
        /*for(int i = 0; i < 52 ; i ++){
            int queueP = 1 - (i&1);
            personQueue[queueP].add(convert(s.next()));
        }*/
    }
}