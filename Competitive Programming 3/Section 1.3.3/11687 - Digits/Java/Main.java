import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    static int countDigits(int number){
        int ans=0;
        for(;number>0;ans++,number/=10);
        return ans;
    }
    static void countUntil1(int number){
        int ans=0;
        for(;number!=1;ans++,number=countDigits(number));
        System.out.printf("%d\n",ans+2);
    }
    public static void main(String[]args){
        while(true){
            String line = s.nextLine();
            if(line.charAt(0)=='E')
                break;
            if(line.charAt(0)=='1' && line.length() == 1)
                System.out.printf("1\n");
            else
                countUntil1(line.length());
        }
    }
}