import java.util.Scanner;
import java.util.ArrayList;

public class Main{
    static Scanner s = new Scanner(System.in);
    static ArrayList<ArrayList<Integer>> shuffles,cards; 
    static String[] toSuit = {"Clubs","Diamonds","Hearts","Spades"};
    static String[] toValue = {"Jack","Queen","King","Ace"};
    static void initialize(int n){
        shuffles = new ArrayList<ArrayList<Integer>>();
        cards = new ArrayList<ArrayList<Integer>>();
        for(int i = 0 ; i < 2 ; i ++)
            cards.add(new ArrayList<Integer>());
        for(int i = 0 ; i < n ; i ++){
            shuffles.add(new ArrayList<Integer>());
        }
        for(int i = 0; i < 52 ; i ++){
            cards.get(0).add(i);
            cards.get(1).add(0);
        }
    }
    static String getValue(int card){
        card%=13;
        if(card<9){
            return Integer.toString(card+2);
        }
        return toValue[card-9];
    }
    public static void main(String[]args){
        int t = Integer.parseInt(s.nextLine());
        s.nextLine();
        for(int cs = 0 ; cs < t; cs++){
            if(cs>0){
                System.out.printf("\n");
            }
            int n = Integer.parseInt(s.nextLine());
            initialize(n);
            for(int i = 0 , processedFromI=0;i<n;){
                String[] tks = s.nextLine().split(" ");
                for(String tk : tks){
                    shuffles.get(i).add(Integer.parseInt(tk)-1);
                    processedFromI++;
                    if(processedFromI==52){
                        processedFromI=0;
                        i++;
                    }
                }
            }
            int shuf = 1;
            while(s.hasNextLine()){
                String line = s.nextLine();
                if(line.compareTo("")==0)
                    break;
                int k = Integer.parseInt(line)-1;
                //shuffle
                int sz=shuffles.get(k).size();
                for(int j = 0 ; j < sz; j++){
                    cards.get(shuf).set(j,cards.get(1-shuf).get(shuffles.get(k).get(j))); 
                }
                shuf=1-shuf;
            }
            //! shuf has the answer
            for(int card : cards.get(1-shuf)){
                System.out.printf("%s of %s\n",getValue(card),toSuit[card/13]);
            }
        }
    }
}