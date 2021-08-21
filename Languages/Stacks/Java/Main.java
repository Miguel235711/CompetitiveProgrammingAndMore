import java.util.Scanner;
import java.util.Stack;

public class Main {
 static Stack<Integer> myStack = new Stack<Integer>();
 public static void main(String[]args){
  for(int i=0;i<5;i++)
   myStack.add(i);
  //myStack=[0,1,2,3,4]
                 //^ search(3)       
  System.out.printf("%d\n",myStack.peek());//4
  System.out.printf("%d\n",myStack.search(3));//2
  //.search() returns -1 if it is not found
  while(!myStack.isEmpty())
   System.out.printf("%d\n",myStack.pop());
 }  
}