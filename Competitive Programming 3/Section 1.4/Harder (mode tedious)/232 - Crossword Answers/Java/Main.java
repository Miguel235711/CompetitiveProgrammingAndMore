import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader;
import java.util.StringTokenizer; 
import java.util.Arrays;

public class Main {
    static int[][]movs={{0,1},{1,0}};
    static String[]names={"Across","Down"};
    static char[][]grid;
    static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 
    static FastReader s=new FastReader();
    static void printAns(int i,int j,int[]mov,int number){
        System.out.printf(" %s%d.",number<10?" ":"",number);
        for(;grid[i][j]!='*';i+=mov[0],j+=mov[1])
            System.out.printf("%c",grid[i][j]);
        System.out.printf("\n");
    }
    public static void main(String[]args){
        for(int cs=1;true;cs++){
            String[] line=s.nextLine().split(" ");
            if(line.length==1)
                return;
            int r=Integer.parseInt(line[0]),c=Integer.parseInt(line[1]);
            int num=0;
            System.out.printf("%spuzzle #%d:\n",cs>1?"\n":"",cs);
            grid=new char[r+2][c+2];
            int lim1=r+2;
            for(int i=0;i<lim1;i++)
                Arrays.fill(grid[i],'*');
            int[][]numbers=new int[r+1][c+1];
            for(int i=1;i<=r;i++){
                String lineS=s.nextLine();
                for(int j=0;j<c;j++){
                    grid[i][j+1]=lineS.charAt(j);
                    if(grid[i][j+1]!='*'&&(grid[i-1][j+1]=='*'||grid[i][j]=='*'))
                        numbers[i][j+1]=++num;
                }
            }
            for (int mov=0;mov<2;mov++){
                System.out.printf("%s\n",names[mov]);
                for(int i=1;i<=r;i++)
                    for(int j=1;j<=c;j++)
                        if(grid[i][j]!='*'&&grid[i-movs[mov][0]][j-movs[mov][1]]=='*')
                            printAns(i,j,movs[mov],numbers[i][j]);
            }
        }
    }
}