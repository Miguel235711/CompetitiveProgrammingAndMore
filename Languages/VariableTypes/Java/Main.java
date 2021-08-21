import java.math.BigInteger;
import java.math.BigDecimal;

public class Main {
  public static void main(String[]args){
    int aI=Integer.MAX_VALUE,bI=Integer.MIN_VALUE;
    System.out.printf("%d %d\n",aI,bI);
    long aL=Long.MAX_VALUE,bL=Long.MIN_VALUE;
    System.out.printf("%d %d\n",aL,bL);
    float aF=Float.MAX_VALUE,bF=-Float.MAX_VALUE;
    System.out.printf("%f %f\n",aF,bF);
    double aD=Double.MAX_VALUE,bD=-Double.MAX_VALUE;
    System.out.printf("%f\n%f\n",aD,bD);
    String s="hello ICPC contestants";
    boolean bb=true;
    char c = 'e';
    Character character ='d';
    System.out.printf("%s %b %c %c\n",s,bb,c,character);
    Integer capitalI=20;
    System.out.printf("%d\n",capitalI);
    Long capitalL=(long)30;
    System.out.printf("%d\n",capitalL);
    BigInteger bigI = new BigInteger("10000000000000000");
    BigInteger bigI2 = new BigInteger("2400000000000000").multiply(bigI);
    bigI=bigI.pow(10000);
    System.out.printf("%s %s\n",bigI.toString(),bigI2);
  }
}