import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    static int sumDigits(int number){
        while(number > 9){
            int digitSum = 0 ;
            for(;number>0;number /= 10){
                digitSum += number % 10;
            }
            number = digitSum;
        }
        return number;
    }
    static int calcValue(String s){
        int sum = 0 ;
        for(int i = 0 ; i < s.length(); i ++){
            char c =  Character.toLowerCase(s.charAt(i));
            if('a'<=c&&c<='z'){
                sum += c-'a'+1;
            }
        }
        return sum;
    }
    public static void main(String[] args){
        while(s.hasNextLine()){
            int sumDigitsA = sumDigits(calcValue(s.nextLine())), sumDigitsB = sumDigits(calcValue(s.nextLine()));
            if(sumDigitsA>sumDigitsB){
                sumDigitsA^=sumDigitsB;
                sumDigitsB^=sumDigitsA;
                sumDigitsA^=sumDigitsB;
            }
            //sumDigitsA <= sumDigitsB
            System.out.printf("%s %%\n",String.format("%.2f",(float)sumDigitsA/sumDigitsB*100));
        }
    }  
}