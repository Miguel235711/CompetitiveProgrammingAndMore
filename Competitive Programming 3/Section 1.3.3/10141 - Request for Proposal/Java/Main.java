import java.util.Scanner;

public class Main{
    static Scanner s = new Scanner(System.in);
    public static void main(String[]args){
        for(int cs=1;true;cs++){
            float minimumCost=Float.MAX_VALUE;
            int mostReq=0;
            String bestAns="";
            String []tk = s.nextLine().split(" ");
            int n = Integer.parseInt(tk[0]) , p = Integer.parseInt(tk[1]);
            if(n==0&&p==0)
                return;
            if(cs>1)
                System.out.printf("\n");
            for(int i = 0 ; i < n ; i ++){
                s.nextLine();
            }
            for(int i = 0 ; i < p ; i ++){
                String name = s.nextLine();
                tk = s.nextLine().split(" ");
                float d = Float.parseFloat(tk[0]);
                int r = Integer.parseInt(tk[1]);
                if(r>mostReq || (r==mostReq && minimumCost > d)){
                    mostReq = r; 
                    minimumCost = d;
                    bestAns = name;
                }
                for(int j = 0 ; j < r ; j ++){
                    s.nextLine();
                }
            }
        System.out.printf("RFP #%d\n%s\n",cs,bestAns);
        }
    }
}