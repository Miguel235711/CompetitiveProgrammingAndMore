import java.util.Scanner;

public class Main {

  
   public static void main(String []args) {
      Scanner input = new Scanner(System.in);
      Double number = input.nextDouble();
      input.close();
      System.out.printf("%.3f\n",number);
   }
}