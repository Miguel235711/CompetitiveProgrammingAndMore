import java.util.Scanner;

public class Main {
    static class es{
        public int month;
        public double percentage;
        es(int month,double percentage){
            this.month=month;
            this.percentage=percentage;
        }
    };
    static es[] records= new es[108];
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args){
        int months;
        while((months=s.nextInt())>=0){
            double downPayment = s.nextDouble(), loanAmount = s.nextDouble();
            int numberOfDepreRecords = s.nextInt();
            double carValue = downPayment + loanAmount;
            downPayment = loanAmount / months;
            int currentMonth = 0 ; 
            for(int i = 0 ; i < numberOfDepreRecords ; i ++){
                records[i] = new es(s.nextInt(),s.nextDouble());
            }
            records[numberOfDepreRecords] = new es(months+1,0);
            outer:
                for(int i = 1 ; i <= numberOfDepreRecords; i ++){
                    for(;currentMonth < records[i].month; currentMonth++){
                        carValue *= 1 - records[i-1].percentage;
                        if(loanAmount-currentMonth*downPayment<carValue){
                            System.out.printf("%d month%s\n",currentMonth,currentMonth!=1?"s":"");
                            break outer;   
                        }
                    }
                }
        }
    }
}