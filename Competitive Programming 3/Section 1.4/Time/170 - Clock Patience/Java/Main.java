import java.util.*;

public class Main{
    static Scanner sc = new Scanner(System.in);
    //A,2,3,4,5,6,7,8,9,T,J,Q,K
    //0,1,2,3,4,...
    static HashMap<Character,Integer> mapCardToInt = new HashMap<Character,Integer>(){
        {
            put('A',0);
            put('T',9);
            put('J',10);
            put('Q',11);
            put('K',12);
        }
    };
    static int cardToInt(char c){
        if('2'<=c&&c<='9')
            return c-'1';
        return mapCardToInt.get(c);
    }
    static class CardC{
        public int v;
        public String card;
        public CardC(int v,String card){
            this.v=v;
            this.card=card;
        }
    }
    public static void main(String[] args){
        while(true){
            Vector<Stack<CardC>> stacks = new Vector<Stack<CardC>>();
            for(int i = 0 ; i < 13 ; i ++)
                stacks.add(new Stack<CardC>());
            for(int i = 0 ;  i < 4 ; i ++)
                for(int j = 12 ; j > -1 ; j --){
                    String cardS = sc.next();
                    if(cardS.charAt(0)=='#')
                        return;
                    stacks.get(j).add(new CardC(cardToInt(cardS.charAt(0)),cardS));
                }
            for(int j = 0 ; j < 13 ; j++){
                Queue<CardC> inter = new LinkedList<CardC>();
                while(!stacks.get(j).isEmpty())
                    inter.add(stacks.get(j).pop());
                while(!inter.isEmpty()){
                    stacks.get(j).add(inter.remove());
                }
            }
            CardC card = stacks.get(12).pop();
            for(int counter=1;;counter++){
                System.out.printf("card:%d %s\n",card.v,card.card);
                if(stacks.get(card.v).isEmpty()){
                    System.out.printf("%02d,%s\n",counter,card.card);
                    break;
                }else
                    card = stacks.get(card.v).pop();
            }
        }
    }
}