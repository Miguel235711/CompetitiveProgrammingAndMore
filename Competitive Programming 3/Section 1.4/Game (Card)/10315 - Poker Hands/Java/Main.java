import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Comparator;

public class Main {
    static Scanner s = new Scanner(System.in);
    static HashMap<Character,Integer> irregularValue = new HashMap<Character,Integer>(){{
        put('T',10);
        put('J',11);
        put('Q',12);
        put('K',13);
        put('A',14);
    }}; 
    static int getValue(String s){
        char x = getVPart(s);
        if(Character.isDigit(x))
            return x-'0';
        //for irregulars
        return irregularValue.get(x);
    }
    static char getVPart(String card){
        return card.charAt(0);
    }
    static char getSuit(String card){
        return card.charAt(1);
    }
    static ArrayList<ArrayList<String>> getSameValue(ArrayList<String>hand){
        int last = -1;
        ArrayList<ArrayList<String>>ans = new ArrayList<ArrayList<String>>();
        ArrayList<String>current= new ArrayList<String>();
        for(String card: hand){
            int val=getValue(card);
            if(val!=last){
                if(!current.isEmpty()){
                    //insert 
                    ans.add(current);
                    current = new ArrayList<String>();
                }
            }
            current.add(card);
            last = val;
        }
        if(!current.isEmpty()){
            //insert 
            ans.add(current);
        }
        return ans;
    }
    static boolean allSameSuit(ArrayList<String>hand){
        char expectedSuit = getSuit(hand.get(0));
        for(int i = 1 ; i < hand.size(); i++){
            if(expectedSuit!=getSuit(hand.get(i)))
                return false;
        }
        return true;
    }
    static boolean isThereGreaterOrEqualToValue(ArrayList<ArrayList<String>>sames,int value){
        for(ArrayList<String> same: sames){
            if(same.size()>=value)
                return  true;
        }
        return false;
    }
    static boolean isThereEqualToValue(ArrayList<ArrayList<String>>sames,int value){
        for(ArrayList<String> same: sames){
            if(same.size()==value)
                return  true;
        }
        return false;
    }
    static boolean allConsecutive(ArrayList<String> hand){
        for(int i = 1 ; i < hand.size(); i++){
            if(getValue(hand.get(i-1))+1!=getValue(hand.get(i)))
                return false;
        }
        return true;
    }
    static int getGreatest(ArrayList<String>l){
        int maxValue = 0;
        for(String x: l){
            maxValue = Math.max(maxValue,getValue(x));
        }
        return maxValue;
    }
    static boolean twoPairs(ArrayList<ArrayList<String>>sames){
        int withSize2=0;
        for(ArrayList<String>same:sames){
            if(same.size()==2)
                withSize2++;
        }
        return withSize2==2;
    }
    static class CustomComparator implements Comparator<String> {
        @Override
        public int compare(String s1, String s2) {
            return getValue(s1)-getValue(s2);
        }
    }
    static ArrayList<ArrayList<String>>cardsWithSameValue = new ArrayList<ArrayList<String>>();
    static int getPartial(ArrayList<String>hand){
        //receive them sorted by value
        cardsWithSameValue = getSameValue(hand);
        /*for(ArrayList<String>same:cardsWithSameValue){
            System.out.printf("same cards:\n");
            for(String card: same){
                System.out.printf("card: %s ",card);
            }
            System.out.printf("\n");
        }*/
        if(allConsecutive(hand)&&allSameSuit(hand))
            //straight flush
            return 8;
        else if(isThereGreaterOrEqualToValue(cardsWithSameValue,4))
            //four of a kind
            return 7;
        else if(isThereEqualToValue(cardsWithSameValue,3)&&isThereEqualToValue(cardsWithSameValue,2))
            //full house
            return 6;
        else if(allSameSuit(hand))
            //flush
            return 5;
        else if(allConsecutive(hand))
            //straight
            return 4;
        else if(isThereGreaterOrEqualToValue(cardsWithSameValue,3))
            //three of a kind
            return 3;
        else if(twoPairs(cardsWithSameValue))
            //two pairs
            return 2;
        else if(isThereEqualToValue(cardsWithSameValue,2))
            //pair
            return 1;
        //high card
        return 0;
    }
    static enum typeAns{
        black,
        white,
        tie
    }
    static int getGreatestFromHands(ArrayList<ArrayList<String>> cardsWithSameValue,int equality){
        for(ArrayList<String>equalHand: cardsWithSameValue){
            if(equalHand.size()==equality){
                return getGreatest(equalHand);
            }
        }
        return -1;
    }
    static typeAns getAns(ArrayList<ArrayList<String>>hands,ArrayList<ArrayList<ArrayList<String>>> cardsWithSameValueOf,int partial){
        ArrayList<String> blackHand = hands.get(0), whiteHand = hands.get(1);
        int szBlH = blackHand.size(), szWhH = whiteHands.size(),b=0,w=0;
        switch (partial) {
            case 8:
                b = getValue(blackHand.get(szBlH-1));
                w = getValue(whiteHand.get(szWhH-1));
                break;
            case 7:
                b = getGreatestFromHands(cardsWithSameValueOf.get(0),4);
                w = getGreatestFromHands(cardsWithSameValueOf.get(1),4);
                break;
            case 6:
                b = getGreatestFromHands(cardsWithSameValueOf.get(0),3);
                w = getGreatestFromHands(cardsWithSameValueOf.get(1),3);
                break;
            case 5:
                b = getValue(blackHand.get(szBlH-1));
                w = getValue(whiteHand.get(szWhH-1)); 
                break;
            case 4:
                b = getValue(blackHand.get(szBlH-1));
                w = getValue(whiteHand.get(szWhH-1));
                break;
            case 3:
                b = getGreatestFromHands(cardsWithSameValueOf.get(0),3);
                w = getGreatestFromHands(cardsWithSameValueOf.get(1),3);
            case 2:
                //pendant
                break;
            case 1:
                b = getGreatestFromHands(cardsWithSameValueOf.get(0),2);
                w = getGreatestFromHands(cardsWithSameValueOf.get(1),2);
                if(b==w){
                    //take from the ones that are not in the pair
                }
                break;
            default:
                
                break;
        }
    }
    public static void main(String[]args){
        while(s.hasNextLine()){
            typeAns ans = typeAns.tie;
            String[] line = s.nextLine().split(" ");
            //System.out.printf("line length: %d\n",line.length);
            ArrayList<Integer>partials=new ArrayList<Integer>();
            ArrayList<ArrayList<ArrayList<String>>>cardsWithSameValueOf = new ArrayList<ArrayList<ArrayList<String>>>();
            ArrayList<ArrayList<String>>hands = new ArrayList<ArrayList<String>>();
            for(int i = 0;i<line.length;){
                ArrayList<String> hand = new ArrayList<String>();
                for(int t=0 ; t < 5 ; t ++,i++){
                    hand.add(line[i]);
                }
                hand.sort(new CustomComparator());
                hands.add(hand);
                /*System.out.printf("hand: ");
                for(String card: hand){
                    System.out.printf("card: %s",card);
                }*/
                partials.add(getPartial(hand));
                cardsWithSameValueOf.add(cardsWithSameValue);
            }
            int a=partials.get(0),b=partials.get(1);
            if(a>b){
                ans = typeAns.black;
            }else if(a<b){
                ans = typeAns.white;
            }else{
                //
                ans = getAns(hands,cardsWithSameValueOf,a);
                /*for(ArrayList<ArrayList<String>> cardsWithSameValue:cardsWithSameValueOf){
                    System.out.printf("Group of equal cards and number of groups of cards with same value: %d\n",cardsWithSameValue.size());
                    for(ArrayList<String>cards: cardsWithSameValue){
                        System.out.printf("cards with same value: ");
                        for(String card: cards){
                            System.out.printf("%s ",card);
                        }
                        System.out.printf("\n");
                    }
                }*/
            }
        }
    }
}