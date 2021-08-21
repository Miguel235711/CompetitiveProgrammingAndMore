import java.util.Scanner;

public class Main{
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args){
        int H;
        while((H=s.nextInt())!=0){
            double pos = 0;
            double U = s.nextDouble();
            int D = s.nextInt(),day=0;
            double F = s.nextDouble();
            F = U*F/100;
            while(0<=pos&&pos<=H){
                day++;
                pos+=Math.max(0.0,U);
                if(pos>H)
                    break;
                pos-=D;
                U-=F;
            }
            System.out.printf("%s on day %d\n",pos<0?"failure":"success",day);
        }
    }
}