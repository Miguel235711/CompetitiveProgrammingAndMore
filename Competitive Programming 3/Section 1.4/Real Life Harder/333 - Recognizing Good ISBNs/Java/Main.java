import java.util.*;

public class Main{
    static Scanner sc = new Scanner(System.in);

    static int convert(char x){
        return '0'<=x&&x<='9'? x-'0' : x=='X' ? 10 : -1; 
    }
    public static void main(String[]args){
        while(sc.hasNextLine()){
            String line = sc.nextLine();
            boolean firstNoSpace = false;
            int sum=0 , factor=10 ;
            for(int i = 0 ; i < line.length(); i ++){
                char c = line.charAt(i);
                if(sum!=-1){ 
                    firstNoSpace=true;
                    if(c!='-'&&c!=' '){
                        int cI = convert(c);
                        if(cI==-1||factor==0||(cI==10&&factor!=1))
                            sum=-1;
                        else
                            sum+=cI*factor--;
                    }
                }
            }
            System.out.printf("%s is %scorrect.\n",line.trim(),factor==0&&sum%11==0?"":"in");
        }
    }
}