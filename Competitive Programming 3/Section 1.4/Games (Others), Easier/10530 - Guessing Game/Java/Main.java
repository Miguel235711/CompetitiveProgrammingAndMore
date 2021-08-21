import java.util.Scanner;
import java.util.ArrayList;

public class Main{
    static Scanner s = new Scanner(System.in);
    static class p{
        int v;
        char flag;
        public p(int v,char flag){
            this.v=v;
            this.flag=flag;
        }
    }  
    public static void main(String[]args){
        while(true){
            ArrayList<p> guesses= new ArrayList<p>();
            boolean honest=true;
            while(true){
                int guessN = Integer.parseInt(s.nextLine());
                if(guessN==0)
                    return;
                char response = s.nextLine().charAt(4);
                if(response=='t'){//output answer
                    for(p el:guesses)
                        if((el.flag=='h'&&el.v<=guessN)||(el.flag=='l'&&el.v>=guessN)){//lie
                            honest=false;
                            break;
                        }
                    break;
                }else{
                    guesses.add(new p(guessN,response));
                }
            }
            System.out.printf("Stan %s\n",honest?"may be honest":"is dishonest");
        }
    }
}