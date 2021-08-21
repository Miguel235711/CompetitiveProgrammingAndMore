import java.util.Scanner;
import java.util.HashMap;

public class Main{
    static final int[][] grid={
        {0,0,1,2,3,0,0},
        {0,0,4,5,6,0,0},
        {7,8,9,10,11,12,13},
        {14,15,16,17,18,19,20},
        {21,22,23,24,25,26,27},
        {0,0,28,29,30,0,0},
        {0,0,31,32,33,0,0}
    };
    static final int[][] movs={{1,0},{0,1},{-1,0},{0,-1}};
    static class coord{
        public int i,j;
        public coord(int i,int j){
            this.i=i;
            this.j=j;
        }
    };
    static coord getCoord(int x){
        if(7<=x&&x<=27)
            return new coord(x/7+1,x%7);
        if(1<=x&&x<=6)
            return new coord((x-1)/3,(x-1)%3+2);
        return new coord((x-28)/3+5,(x-1)%3+2);
    }
    static Scanner s=new Scanner(System.in);
    static boolean inside(int i,int j){
        return i>-1&&j>-1&&i<7&&j<7&&grid[i][j]!=0;
    }
    static boolean visited(int i,int j,boolean [][] vis){
        return inside(i,j)&&vis[i][j];
    }
    static boolean free(int i,int j,boolean [][] vis){
        return inside(i,j)&&!vis[i][j];
    }
    public static void main(String[] args){
        System.out.printf("HI Q OUTPUT\n");
        for(int n=s.nextInt();n>0;n--){
            int x,sum=0;
            boolean [][] vis = new boolean[7][7];
            while((x=s.nextInt())!=0){
                //visit
                coord c = getCoord(x);
                sum+=x;
                vis[c.i][c.j]=true;
            }
            //try to make k movements
            int origX=0,maxTarget,intermediary=0;
            do {
                maxTarget=-1;
                for(int i=0;i<7;i++)
                    for(int j=0;j<7;j++){
                        if(vis[i][j]){
                            //for every movement:
                                //1. check if adjacent is part of grid 
                            for(int mov=0;mov<4;mov++){
                                if(visited(i+movs[mov][0],j+movs[mov][1],vis)&&free(i+movs[mov][0]*2,j+movs[mov][1]*2,vis)){
                                    int target=grid[i+movs[mov][0]*2][j+movs[mov][1]*2];
                                    if(target>maxTarget||(target==maxTarget&&grid[i][j]>origX)){
                                        origX=grid[i][j];
                                        maxTarget=target;
                                        intermediary=grid[i+movs[mov][0]][j+movs[mov][1]];
                                    }
                                }
                            }
                        }
                    }
                if(maxTarget!=-1){
                    coord targetC = getCoord(maxTarget),origC=getCoord(origX),interC=getCoord(intermediary);
                    vis[targetC.i][targetC.j]=true;
                    vis[origC.i][origC.j]=vis[interC.i][interC.j]=false;
                    sum+=-origX-intermediary+maxTarget;
                }
            }while(maxTarget!=-1);//maxTargetX should be -1 when movement found
            System.out.printf("%d\n",sum);
        }
        System.out.printf("END OF OUTPUT\n");
    }
}