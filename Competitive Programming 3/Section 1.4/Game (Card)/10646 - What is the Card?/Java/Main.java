import java.util.Scanner;
import java.util.Queue;
import java.util.ArrayList;
import java.util.LinkedList;

public class Main{
    static Scanner s = new Scanner(System.in);
    static int getValue(String card){
        if(Character.isDigit(card.charAt(0)))
            return card.charAt(0)-'0';
        return 10;
    } 
    public static void main(String[]args){
        int t = Integer.parseInt(s.next());
        for(int cs=1; cs<=t ; cs++){
            ArrayList<String> st = new ArrayList<String>();
            Queue<String> temp = new LinkedList<>();
            for(int i = 0; i < 27 ; i ++){
                st.add(s.next());
            }
            for(int i = 0 ; i < 25; i ++){
                temp.add(s.next());
            }
            int y=0;
            for(int i = 0 ; i < 3 ; i ++){
                int val = getValue(st.get(st.size()-1));
                st.remove(st.size()-1);
                y+=val;
                for(int j = 10-val ; j > 0 ; j --){
                    st.remove(st.size()-1);
                }
            }
            while(!temp.isEmpty()){
                st.add(temp.poll());
            }
            System.out.printf("Case %d: %s\n",cs,st.get(y-1));
        }
    }
}