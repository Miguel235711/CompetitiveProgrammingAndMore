import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        Scanner s = new Scanner(System.in);
        int k;
        while((k = s.nextInt()) != 0){
            int n = s.nextInt(), m = s.nextInt();
            for(int i = 0 ; i < k ; i ++){
                int x = s.nextInt(), y = s.nextInt();
                String ans = "divisa";
                if(x!=n && y != m){
                    if(y > m ){
                        if(x < n){
                            ans = "NO";
                        }else{
                            ans = "NE";
                        }
                    }else{
                        if(x < n){
                            ans = "SO";
                        }else{
                            ans = "SE";
                        }
                    }
                }
                System.out.printf("%s\n",ans);
            }
        }
    }
}