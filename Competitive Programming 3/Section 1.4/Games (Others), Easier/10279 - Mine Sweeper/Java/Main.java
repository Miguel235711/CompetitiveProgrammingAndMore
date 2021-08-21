import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    static int[][] movs = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    static char getAns(char c,boolean showMines){
        if(c=='*')
            return showMines?'*':'.';
        return c;
    }
    static int convert(char c){
        return c=='*'?1:0;
    }
    public static void main(String[]args){
        int t = Integer.parseInt(s.nextLine()),n;
        for(int cs=0;cs<t;cs++){
            if(cs>0)
                System.out.printf("\n");
            s.nextLine();
            n=Integer.parseInt(s.nextLine());
            char[][]grid=new char[n+2][n+2];
            for(int i=1;i<=n;i++){
                String line = s.nextLine();
                for(int j=1;j<=n;j++)
                    grid[i][j]=line.charAt(j-1);
            }
            boolean showMines=false;
            for(int i=1;i<=n;i++){
                String line = s.nextLine();
                for(int j=1;j<=n;j++){
                    if(line.charAt(j-1)=='x')//touched
                        if(grid[i][j]=='*') //bomb
                            showMines=true;
                        else {//not bomb, sum up adjacents
                            grid[i][j]='0';
                            for(int mov=0;mov<8;mov++)
                                grid[i][j]+=convert(grid[i+movs[mov][0]][j+movs[mov][1]]);
                        }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    System.out.printf("%c",getAns(grid[i][j],showMines));
                }
                System.out.printf("\n");
            }
        }
    }
}