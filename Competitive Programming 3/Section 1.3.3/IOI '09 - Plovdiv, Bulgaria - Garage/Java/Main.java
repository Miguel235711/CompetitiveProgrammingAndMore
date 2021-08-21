import java.util.Scanner;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main{
    static Scanner s = new Scanner(System.in); 
    static int[] costPerKilo = new int[102],weight = new int[2002],slotTaken = new int[2002];
    public static void main(String[]args){
        int n = s.nextInt(), m = s.nextInt(),cost=0;
        PriorityQueue<Integer> available = new PriorityQueue<Integer>();
        for(int i = 1 ; i <= n ; i ++){
            costPerKilo[i]=s.nextInt();
            available.add(i);
        }
        for(int i = 1 ; i <= m ; i ++){
            weight[i]=s.nextInt();
        }
        Queue<Integer> waitingLine = new LinkedList<>();
        for(int m2 = m << 1;m2>0;m2--){
            int car = s.nextInt();
            if(car<0){
                available.add(slotTaken[-car]);
            }else{
                waitingLine.add(car);
            }
            while(!available.isEmpty()&&!waitingLine.isEmpty()){
                int slot = available.poll(), carRemoved = waitingLine.remove();
                cost += costPerKilo[slot] * weight[carRemoved]; 
                slotTaken[carRemoved] = slot;
            }
        }
        System.out.printf("%d\n",cost);
    }
}