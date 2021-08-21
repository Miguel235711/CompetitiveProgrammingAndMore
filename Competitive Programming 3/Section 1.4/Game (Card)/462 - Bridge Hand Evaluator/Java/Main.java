import java.util.Scanner;
import java.util.HashMap;
import java.util.Arrays;

public class Main {
    static Scanner s = new Scanner(System.in);
    static HashMap<Character,Integer> mapToValue = new HashMap<Character,Integer>(){{
        put('A',4);
        put('K',3);
        put('Q',2);
        put('J',1);
    }};
    static HashMap<Character,Integer> mapToIndex = new HashMap<Character,Integer>(){{
        put('S',0);
        put('H',1);
        put('D',2);
        put('C',3);
    }};
    static int[] amount;
    static boolean[] stopped;
    static int cardValue(String x){
        char c = x.charAt(0);
        if(Character.isDigit(c)||c=='T')
            return 0;
        return mapToValue.get(c);
    }
    public static void main(String[] args){
        while(s.hasNextLine()){
            int ans=0;
            int pointsSuitBid = 0,stoppedSuits=0,maxAmountOfCards=0; 
            char suitWithMoreCards='S';
            amount = new int[4];
            stopped = new boolean[4];
            String[] line = Arrays.stream(s.nextLine().split(" ")).filter(tk->tk.length()!=0).toArray(String[]::new);
            for(String card: line){//rule 1
                //System.out.printf("card: %s\n",card);
                int suitIndex = mapToIndex.get(card.charAt(1));
                pointsSuitBid+=cardValue(card);
                amount[suitIndex]++; //incremente by 1 amount of cards of suit
                if(maxAmountOfCards<amount[suitIndex]||(maxAmountOfCards==amount[suitIndex]&&suitIndex<mapToIndex.get(suitWithMoreCards))){
                    suitWithMoreCards = card.charAt(1);
                    maxAmountOfCards = amount[suitIndex];
                }
            }
            for(String card: line){
                int suitIndex = mapToIndex.get(card.charAt(1));
                int suitAmount = amount[suitIndex];
                if((card.charAt(0)=='K' && suitAmount<2)||(card.charAt(0)=='Q' && suitAmount<3)||(card.charAt(0)=='J' && suitAmount<4))
                    //rule from 2 to 4
                    pointsSuitBid--;
                //stop suits
                if(!stopped[suitIndex]&&((card.charAt(0)=='A')||(card.charAt(0)=='K'&&suitAmount>1)||(card.charAt(0)=='Q'&&suitAmount>2))){
                    stopped[suitIndex]=true;
                    stoppedSuits++;
                }
            }
            //System.out.printf("stoppedSuits: %d\n",stoppedSuits);
            if(stoppedSuits==4&&pointsSuitBid>15){
                ans=1;//no trump
            }else{
                //try suit bid
                //rule from 5 to 7
                for(int i = 0 ; i < 4 ; i ++){
                    if(amount[i]==2){
                        pointsSuitBid++;
                    }else if(amount[i]<2){
                        pointsSuitBid+=2;
                    }
                }
                if(pointsSuitBid>13){
                    ans=2;
                }
            }
            System.out.printf("%s\n",ans==0?"PASS":(ans==1?"BID NO-TRUMP":"BID "+suitWithMoreCards));
        }
    }
}