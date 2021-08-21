import java.util.Scanner;

public class Main{
  static Scanner s=new Scanner(System.in);
  static int[] arr = new int[1000002];
  public static void main(String[]args){
    int N=s.nextInt();
    for(int i=0;i<N;i++)
      arr[i]=s.nextInt();
    System.out.printf("(");
    for(int i=0;i<N;i++)
      System.out.printf("%d%s",arr[i],i+1<N?",":"");
    System.out.printf(")\n");
  }
}