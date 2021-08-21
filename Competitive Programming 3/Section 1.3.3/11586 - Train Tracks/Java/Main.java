import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args){
        for(int cases = Integer.parseInt(s.nextLine()); cases > 0 ; cases --){
            String[] tk = s.nextLine().split(" ");
            int FFs=0,MMs=0;
            for(int i = 0; i < tk.length; i++){
                if(tk[i].compareTo("FF")==0){
                    FFs++;
                }else if(tk[i].compareTo("MM")==0){
                    MMs++;
                }
            }
            System.out.printf("%s\n",tk.length==1||Math.abs(FFs-MMs)>0?"NO LOOP":"LOOP");
        }
    }
}