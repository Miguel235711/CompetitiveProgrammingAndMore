import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    static Scanner s = new Scanner(System.in);
    static ArrayList<Integer> aArr;
    public static void main(String[]args){
        while(true){
            aArr = new ArrayList<Integer>();
            int a=s.nextInt(),b=s.nextInt(),pointer = 0,amountB=0,amountA=0,last=0;
            if(a==0&&b==0)
                break;
            for(int i = 0 ; i < a ; i ++){
                int x = s.nextInt();
                if(last!=x){
                    aArr.add(x);
                    last = x;
                }
            }
            last=0;
            for(int i = 0 ; i < b ; i ++){
                int x = s.nextInt();
                if(x!=last){
                    for(;pointer<aArr.size()&&aArr.get(pointer)<x;pointer++){
                        amountA++;
                    }
                    if(pointer==aArr.size()||aArr.get(pointer)!=x){
                        amountB++;
                    }
                    if(pointer<aArr.size()&&aArr.get(pointer)==x)
                        pointer++;
                    last=x;
                }
            }
            for(;pointer<aArr.size();pointer++){
                    amountA++;
            }
            System.out.printf("%d\n",Math.min(amountA,amountB));
        }
    }
}