import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args){
        while(s.hasNextInt()){
            int n = s.nextInt(), b = s.nextInt(), h = s.nextInt(), w = s.nextInt(),minAns = Integer.MAX_VALUE;
            for(int ih = 0; ih < h ; ih ++){
                int pi = s.nextInt() ; 
                boolean possible = false;
                for(int jw = 0 ; jw < w ; jw++){
                    if(s.nextInt()>=n){
                        possible=true;
                    }
                }
                if(possible && pi*n<=b){
                    minAns = Integer.min(minAns,pi*n);
                }
            }
            System.out.println(minAns==Integer.MAX_VALUE?"stay home":minAns);
        }
    }
}