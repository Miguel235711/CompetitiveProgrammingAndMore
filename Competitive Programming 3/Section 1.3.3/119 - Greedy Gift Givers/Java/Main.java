import java.util.Scanner;
import java.util.HashMap;
import java.util.LinkedList;

public class Main{
    static Scanner s = new Scanner(System.in);
    static int[] gainLoss = new int[12];
    static String[] personName = new String[12];
    static HashMap <String,Integer> toPosition;
    public static void main(String[] args){
        while(s.hasNext()){
            toPosition = new HashMap<String,Integer>();
            int n = Integer.parseInt(s.next());
            //register people
            for(int i = 0 ; i < n ; i ++){
                personName[i]= new String(s.next());
                gainLoss[i]=0;
                toPosition.put(personName[i],i);
            }
            //simulate
            for(int i = 0 ; i < n ; i ++){
                String person = s.next();
                int money = Integer.parseInt(s.next()),numberOfGifts=Integer.parseInt(s.next()),evenMoney = numberOfGifts!=0? money / numberOfGifts:0;
                int position = toPosition.get(person);
                gainLoss[position]+=-evenMoney*numberOfGifts;
                for(int j = 0 ; j < numberOfGifts ; j ++){
                    String toPerson = s.next();
                    int positionPerson = toPosition.get(toPerson);
                    gainLoss[positionPerson]+=evenMoney;
                }
            }
            for(int i = 0 ; i < n ; i ++){
                System.out.printf("%s %d\n",personName[i],gainLoss[i]);
            }
            if(s.hasNext()){
                System.out.print("\n");
            }
        }
    }
}