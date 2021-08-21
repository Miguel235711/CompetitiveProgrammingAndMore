import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args){
        for(int n = s.nextInt() ; n > 0 ; n --){
            long ans = 0;
            int sz,animals,friendliness; 
            for(int farmers = s.nextInt(); farmers > 0 ; farmers -- ) {
                sz = s.nextInt();
                animals = s.nextInt();
                friendliness = s.nextInt();
                ans += (long)sz * friendliness;
            }
            System.out.printf("%d\n",ans); 
        }
    }
}