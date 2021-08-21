import java.util.*;

public class Main{
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args){
        int t = Integer.parseInt(sc.nextLine());
        for(int cs = 1 ; cs <= t ; cs ++){
            String line = sc.nextLine();
            int total = 0 ;
            for(int i = 0 ; i < line.length(); i++){
                char c = line.charAt(i);
                if(c==' ')
                    total++;
                else{
                    int value = c-'a';
                    if(c=='s' || c == 'z')
                        total+= 4;
                    else{
                        if(c>'s')
                            value--;
                        total +=(value%3)+1;
                    }
                }
            }
            System.out.printf("Case #%d: %d\n",cs,total);
        } 
    }
}