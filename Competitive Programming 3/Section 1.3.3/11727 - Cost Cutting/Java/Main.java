import java.util.Scanner;
import java.util.Arrays;

public class Main{
    static int nums[] = new int[3];
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int cs = 1 ; cs <= t ; cs++){
            for(int i = 0 ; i < 3 ; i ++){
                nums[i] = s.nextInt();
            }
            Arrays.sort(nums);
            System.out.printf("Case %d: %d\n",cs,nums[1]);
        }
    }
}