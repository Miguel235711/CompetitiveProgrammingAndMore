import java.util.Scanner;
import java.util.HashSet;

public class Main {
    static Scanner s = new Scanner(System.in);
    static char[][] matrix = new char[3][3];
    static enum who{
        o,
        x 
    }
    static who person;
    static int[][] movs = {{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1}};
    static boolean insideLimit(int x){
        return -1<x&&x<3;
    }
    static boolean insideLimits(int i,int j){
        return insideLimit(i)&&insideLimit(j);
    }
    static int wins(){
        int countRawWins=0;
        HashSet<Integer>differentMovements= new HashSet<Integer>();
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(matrix[i][j]!='.')
                    for(int mov = 0;mov < 8;mov ++){
                        int iS=i,jS=j;
                        for(int t=0;insideLimits(iS,jS)&&t<3&&matrix[iS][jS]==matrix[i][j];t++,iS+=movs[mov][0],jS+=movs[mov][1]){
                            if(t==2){
                                person=matrix[i][j]=='O'?who.o:who.x;
                                countRawWins++;
                                differentMovements.add(mov);
                            }
                        }
                    }
            }
        }
        return differentMovements.size()==4 && countRawWins==4 && person == who.x ? 1 : countRawWins >> 1 ;
    }
    public static void main(String[] args){
        int n = Integer.parseInt(s.nextLine());
        for(int c=0;c<n;c++){
            if(c>0)
                s.nextLine();
            int dif=0;
            for(int i=0;i<3;i++){
                String line = s.nextLine();
                for(int j=0;j<3;j++){
                    matrix[i][j]=line.charAt(j);
                    dif+= line.charAt(j) == 'O' ? -1 : (line.charAt(j) == 'X' ? 1 : 0);
                }
            }
            int winCount = wins();
            //System.out.println(person==who.o?"O":"X");
            //System.out.printf("win count=%d\n",winCount);
            System.out.printf("%s\n",(winCount==0&&-1<dif&&dif<2)||(winCount==1&&((person==who.o&&dif==0)||(person!=who.o&&dif==1)))?"yes":"no");
        }
    }
}