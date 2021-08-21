import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class Main{
 static Queue<Integer> myQueue=new LinkedList<Integer>();
 //or
 //static Queue<Integer> myQueue=new ArrayDeque<Integer>();//it depends on performance and concurrency characteristics we want
 static Scanner sc = new Scanner(System.in);
 public static void main(String[]args){
 for(int n=sc.nextInt();n>0;n--){
  int x=sc.nextInt();
  myQueue.add(x); 
 }
 System.out.printf("%d\n",myQueue.element());//throws exception if empty
 //System.out.printf("%d\n",myQueue.peek());//null if empty
 while(!myQueue.isEmpty())
  System.out.printf("%d\n",myQueue.remove()); //throws exception if empty
  //System.out.printf("%d\n",myQueue.poll());//null if empty
 }
}