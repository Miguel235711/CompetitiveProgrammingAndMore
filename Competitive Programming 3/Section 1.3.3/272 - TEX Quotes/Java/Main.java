import java.util.Scanner;

public class Main {
    public static void main(String []args){
        Scanner s = new Scanner(System.in);
        int time = 0 ; 
        while(s.hasNextLine()){
            char[] line = s.nextLine().toCharArray();
            //process line
            String transLine="";
            for(char x: line){
                if(x=='"'){
                    if((time&1)==1){
                        transLine+="''";
                    }else{
                        transLine+="``";
                    }
                    time = (time+1) & 1 ; 
                }else{
                    transLine+=x;
                }
            }
            System.out.printf("%s\n",transLine);
        }
    }
}