import java.util.Scanner;
import java.util.Arrays;

public class Main{
    static Scanner s = new Scanner(System.in);
    static char[][]field;
    static int[][]movs={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    public static void main(String[]args){
        for(int cs=1;true;cs++){
            String[] tk = s.nextLine().split(" ");
            if(tk[0].compareTo("0")==0)
                break;
            if(cs>1)
                System.out.printf("\n");
            System.out.printf("Field #%d:\n",cs);
            int n=Integer.parseInt(tk[0]),m=Integer.parseInt(tk[1]);
            field = new char[n+2][m+2];
            for(int i = 1 ; i <= n ; i ++){
                String line = s.nextLine();
                for(int j = 1 ; j <= m;j++)
                    field[i][j]=line.charAt(j-1)=='.'?'0':'1';
            }
            for(int i = 1 ; i <= n ; i ++){
                for(int j = 1 ; j <= m ; j ++){
                    char ans='*';
                    if(field[i][j]!='1'){
                        ans='0';
                        for(int mov=0;mov<8;mov++)
                            if(field[i+movs[mov][0]][j+movs[mov][1]]!='\0')
                                ans+=field[i+movs[mov][0]][j+movs[mov][1]]-'0';
                    }
                    System.out.printf("%c",ans);
                }
                System.out.printf("\n");
            }
        }
    }
}