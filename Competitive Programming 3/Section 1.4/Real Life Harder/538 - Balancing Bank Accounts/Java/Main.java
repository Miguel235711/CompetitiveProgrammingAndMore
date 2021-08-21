import java.util.*;

public class Main{
    static Scanner sc = new Scanner(System.in);
    static class S{
        public String name;
        public int amount;
        public S(String name,int amount){
            this.name=name;
            this.amount=amount;
        }
    }
    public static void main(String[]args){
        int n,t;
        for(int cs=1;(n=sc.nextInt())!=0;cs++){
            t = sc.nextInt();
            System.out.printf("Case #%d\n",cs);
            HashMap<String,Integer> balance = new HashMap<String,Integer>();
            for(int i = 0 ; i < n ; i++)
                balance.put(sc.next(),0);
            for(int i = 0 ; i < t ; i ++){
                String n1 = sc.next(), n2 = sc.next();
                int amount = sc.nextInt();
                balance.put(n1,balance.get(n1)-amount);
                balance.put(n2,balance.get(n2)+amount);
            }
            Vector<S> positives = new Vector<S>(), negatives = new Vector<S>();
            int iP = 0 , iN = 0 ;
            for(Map.Entry b : balance.entrySet()){
                String name = (String)b.getKey();
                int amount = (int)b.getValue();
                if (amount > 0)
                    positives.add(new S(name,amount));
                else if(amount < 0)
                    negatives.add(new S(name,-amount));
                String aS,bS;
                amount = 0 ;
                while(iP<positives.size()&&iN<negatives.size()){
                    aS=positives.get(iP).name;
                    bS=negatives.get(iN).name;
                    if(positives.get(iP).amount<negatives.get(iN).amount){
                        negatives.get(iN).amount-= amount = positives.get(iP++).amount;
                    }else if(positives.get(iP).amount>negatives.get(iN).amount){
                        positives.get(iP).amount-= amount = negatives.get(iN++).amount;
                    }else{
                        amount=positives.get(iP).amount;
                        iN++;
                        iP++;
                    }
                    System.out.printf("%s %s %d\n",aS,bS,amount);
                }
            }
            System.out.println(); 
        }
    }
}