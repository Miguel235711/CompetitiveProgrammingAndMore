import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[]args){
        System.out.println("Lumberjacks:");
        for(int t = s.nextInt(); t > 0; t --){
            int last=0;
            boolean negativeDif = false,positiveDif = false;
            for(int i = 0 ; i < 10 ; i ++){
                int number = s.nextInt();
                if(i>0){
                    if(number-last>0){
                        //System.out.printf("%d %d",number,last);
                        positiveDif=true;
                    }else if(number-last<0){
                        negativeDif=true;
                    }
                }
                last = number;
            }
            System.out.printf("%s\n",positiveDif^negativeDif?"Ordered":"Unordered");
        }
    }
}