import java.util.Scanner;

public class Main {
    static Scanner scan = new Scanner(System.in);

    static String getReversed(String x){
        return new StringBuilder(x).reverse().toString();
    }
    static String add(String a,String b){
        return Integer.toUnsignedString(Integer.parseUnsignedInt(a)+Integer.parseUnsignedInt(b)); 
    }
    public static void main(String[]args){
        for(int cs = scan.nextInt(); cs > 0 ; cs --){
            String s = scan.next();
            int ite=0;
            for(;;ite++){
                String reversed = getReversed(s);
                if(s.equals(reversed))
                    break;
                s = add(s,reversed);
            }
            System.out.printf("%d %s\n",ite,s);
        }
    }
}