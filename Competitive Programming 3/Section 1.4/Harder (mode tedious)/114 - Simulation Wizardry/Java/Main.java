import java.util.Scanner;

public class Main {
    static class bumper{
        public int val,cost;
        public bumper(int val,int cost){
            this.val=val;
            this.cost=cost;
        }
    }
    static int n,m,costWall;
    static Scanner s = new Scanner(System.in);
    static int turnRight(int dir){
        return dir==0?3:dir-1;
    }
    static int[][] movs={{0,1},{1,0},{0,-1},{-1,0}};
    static boolean isWall(int x,int y){
        return x==1||y==1||x==m||y==n;
    }
    static int simulation(int x,int y,int dir,int life,bumper[][] grid){
        int ans=0;
        life--;
        for(;life>0;life--){
            //move
            y+=movs[dir][0];
            x+=movs[dir][1];
            boolean isW = isWall(x,y);
            if(isW || grid[y][x]!=null){
                if(isW)
                    life-=costWall;
                else{
                    ans+=grid[y][x].val;
                    life-=grid[y][x].cost;
                }
                y-=movs[dir][0];
                x-=movs[dir][1];
                dir=turnRight(dir);
            }
        }
        return ans;
    }
    public static void main(String[]args){
        m=s.nextInt();
        n=s.nextInt();
        costWall=s.nextInt();
        int p=s.nextInt(),ans=0;
        bumper[][] grid = new bumper[n+1][m+1];
        for(int i=0;i<p;i++){
            int x=s.nextInt(),y=s.nextInt();
            grid[y][x]=new bumper(s.nextInt(),s.nextInt());
        }
        while(s.hasNextInt()){
            int x=s.nextInt(),y=s.nextInt(),dir=s.nextInt(),life=s.nextInt();
            int subAns=simulation(x,y,dir,life,grid);
            ans+=subAns;
            System.out.printf("%d\n",subAns);
        }
        System.out.printf("%d\n",ans);
    }   
}