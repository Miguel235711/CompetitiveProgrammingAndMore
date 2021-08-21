import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        while(s.hasNextLine()){
            //new case 
            int sum = 0, x;
            for(int k = s.nextInt();k>0;k--){
                x = s.nextInt();
                sum += x ; 
            }
            System.out.printf("%d\n",sum);
        }
    }
}