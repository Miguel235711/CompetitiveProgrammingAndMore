import java.util.Scanner;

public class Main{
    static int maxLength = 1000002;
    static Scanner s = new Scanner(System.in);
    static int[] acum = new int [maxLength];
    static boolean same(int i,int j){
        if(i>j){
            i^=j;
            j^=i;
            i^=j;
        }
        //i<=j
        int rangeSum = acum[j+1]-acum[i];
        return rangeSum==0 || rangeSum == j - i + 1 ;
    }
    public static void main(String[]args){
        for(int cs = 1 ; s.hasNextLine();cs++){
            String secuence = s.nextLine();
            for(int i = 0 ; i < secuence.length(); i++){
                acum[i+1]=acum[i]+secuence.charAt(i)-'0';
            }
            String[] tk;
            System.out.printf("Case %d:\n",cs);
            for(int n = Integer.parseInt(s.nextLine()); n > 0 ; n --){
                tk = s.nextLine().split(" ");
                System.out.printf("%s\n",same(Integer.parseInt(tk[0]),Integer.parseInt(tk[1]))?"Yes":"No");
            }
        }
    }
}