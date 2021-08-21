import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

public class Main{
    static Scanner s = new Scanner(System.in);
    static int[]difOutside={1,1,-1,-1},difInside={1,-1,1,-1},begOutside,begInside;
    static int N;
    static ArrayList<int[][]> visitedGrids;
    static void toggle(int i,int j){
        if(!visitedGrids.isEmpty()){
            int[][] orig = visitedGrids.get(visitedGrids.size()-1);
            int[][] cp = new int[N][];
            for(int ii=0;ii<orig.length;ii++)
                cp[ii]=Arrays.copyOf(orig[ii],N);
            visitedGrids.add(cp);
        }
        else
            visitedGrids.add(new int[N][N]);
        visitedGrids.get(visitedGrids.size()-1)[i][j]=1-visitedGrids.get(visitedGrids.size()-1)[i][j];
    }
    static boolean areEqual(int[][] gridNormal,int[][] gridEspecial,int mov){
        for(int outside=begOutside[mov],i=0;i<N;outside+=difOutside[mov],i++)
            for(int inside=begInside[mov],j=0;j<N;inside+=difInside[mov],j++){
                int one=outside,two=inside;
                if(mov==1||mov==2){
                    one^=two;
                    two^=one;
                    one^=two;
                }
                if(gridNormal[i][j]!=gridEspecial[one][two])
                    return false;
            }
        return true;
    }
    static boolean loses(){
        int lim = visitedGrids.size()-1;
        for(int i=0;i<lim;i++)
            for(int mov=0;mov<4;mov++)
                if(areEqual(visitedGrids.get(i),visitedGrids.get(visitedGrids.size()-1),mov))
                    return true;
        return false;
    }
    static void init(){
        begOutside=new int[]{0,0,N-1,N-1};
        begInside=new int[]{0,N-1,0,N-1};
        visitedGrids=new ArrayList<int[][]>();
    }
    public static void main(String[]args){
        while(true){
            N = s.nextInt();
            if(N==0)
                return;
            init();
            boolean draw=true;
            int lim=N<<1;
            for(int t=0;t<lim;t++){
                int i=s.nextInt()-1,j=s.nextInt()-1;
                s.next();
                if (draw){
                    toggle(i,j);
                    if(loses()){
                        System.out.printf("Player %d wins on move %d",2-(t&1),t+1);
                        draw=false;
                    }
                }
            }
            if(draw)
                System.out.printf("Draw");
            System.out.printf("\n");
        }
    }
}