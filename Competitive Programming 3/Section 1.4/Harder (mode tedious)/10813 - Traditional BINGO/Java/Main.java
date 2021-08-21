import java.util.Scanner;

public class Main{
    static Scanner s = new Scanner(System.in);
    static int movs[][]={{1,0},{0,1},{1,1},{1,-1}};
    static boolean[][] vis;
    static int whichMovs[][]={{2,3,0,1},{2,0,1},{3,0,1},{1,0}};
    static class coord{
        public int i,j;
        public coord(int i,int j){
            this.i=i;
            this.j=j;
        }
    }
    static coord[] getDiagonalInit = {null,null,new coord(1,1),new coord(1,5)};
    static coord getCoord(coord coordinates,int chosenMov){
        coord newCoordinates = new coord(coordinates.i,coordinates.j);
        if(chosenMov==0)
            newCoordinates.i=1;
        else if(chosenMov==1)
            newCoordinates.j=1;
        else{
            newCoordinates.i=getDiagonalInit[chosenMov].i;
            newCoordinates.j=getDiagonalInit[chosenMov].j;
        }
        return newCoordinates;
    }
    static boolean insideLimit(int x){
        return 0<x&&x<6;
    }
    static boolean insideLimits(coord coordinates){
        return insideLimit(coordinates.i)&&insideLimit(coordinates.j);
    }
    static boolean visitAndHandle(coord coordinates){
        vis[coordinates.i][coordinates.j]=true;
        int chosenMov = 3;
        if(coordinates.i==3&&coordinates.j==3)
            chosenMov=0;
        else if(coordinates.i==coordinates.j)
            chosenMov=1;
        else if(coordinates.i+coordinates.j==6)
            chosenMov=2;
        //handle
        for(int mov = 0; mov < whichMovs[chosenMov].length;mov++){
            int movPos = whichMovs[chosenMov][mov];
            coord current = getCoord(coordinates,movPos);

            boolean foundAnswer=true;
            
            for(;insideLimits(current);current.i+=movs[movPos][0],current.j+=movs[movPos][1]){
                if(!vis[current.i][current.j]){
                    foundAnswer=false;
                    break;
                }
            }
            if(foundAnswer)
                return true;
        }
        return false;
    }
    public static void main(String[]args){
        for(int n=s.nextInt();n>0;n--){
            vis = new boolean[6][6];
            coord[] bucket = new coord[76];
            for(int i=1;i<=5;i++){
                int lim = i==3 ? 4 : 5;
                for(int j=1;j<=lim;j++){
                    bucket[s.nextInt()]=new coord(i,j+(lim==4&&j>2 ? 1 : 0));
                }
            } 
            boolean shouldBeProcessed=true;
            for(int i=0;i<75;i++){
                int card = s.nextInt();
                if(shouldBeProcessed){
                    coord chosenOne = bucket[card];
                    if(chosenOne==null&&!vis[3][3])
                        //mark center
                        chosenOne = new coord(3,3);
                    if(chosenOne!=null&&visitAndHandle(chosenOne)){
                        System.out.printf("BINGO after %d numbers announced\n",i+1);
                        shouldBeProcessed=false;
                    }
                }
            }
        }
    }
}