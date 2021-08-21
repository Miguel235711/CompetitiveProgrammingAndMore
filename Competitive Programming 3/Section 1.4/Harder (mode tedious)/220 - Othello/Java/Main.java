import java.util.ArrayList;
import java.util.Scanner;

public class Main{
    static int[][] movs={{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
    static char[][] grid=new char[8][8];
    static boolean inLimit(int i,int j){
        return i>-1&&j>-1&&i<8&&j<8;
    }
    static class brack{
        public int[] mov;
        public int times;
        public brack(int[]mov,int times){
            this.mov=mov;
            this.times=times;
        }
    }
    static int calcDif(int i1,int i2,int j1,int j2){
        return Math.max(Math.abs(j2-j1),Math.abs(i2-i1));
    }
    static int[] possibleLimitCoordinate(int[]mov,int i,int j,char currentPlayer){
        //we are sure that i,j is empty when calling this function
        int iN=i+mov[0],jN=j+mov[1];
        char nextP=nextPlayer(currentPlayer);
        while(inLimit(iN,jN)&&grid[iN][jN]==nextP){
            iN+=mov[0];
            jN+=mov[1];
        }
        if(inLimit(iN,jN)&&grid[iN][jN]==currentPlayer&&calcDif(i,iN,j,jN)>1)
            return new int[]{iN,jN};
        return new int[]{};
    }
    static void listPossibleMoves(char currentPlayer){
        boolean atLeastOne=false;
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                if(grid[i][j]=='-')
                    for(int mov=0;mov<8;mov++)
                        if(possibleLimitCoordinate(movs[mov],i,j,currentPlayer).length>0){
                            System.out.printf("%s(%d,%d)",atLeastOne?" ":"",i+1,j+1);
                            atLeastOne=true;
                            break;
                        }
        System.out.printf("%s\n",atLeastOne?"":"No legal move.");
    }
    static ArrayList<brack> getBracketed(char currentPlayer,int i,int j){
        ArrayList<brack> bracketed=new ArrayList<>();
        for(int mov=0;mov<8;mov++){
            int[] limitCoord=possibleLimitCoordinate(movs[mov],i,j,currentPlayer);
            if(limitCoord.length!=0)
                bracketed.add(new brack(movs[mov],calcDif(i,limitCoord[0],j,limitCoord[1])-1));
        }
        return bracketed;
    }
    static char nextPlayer(char currenPlayer){
        return currenPlayer=='B'?'W':'B';
    }
    static void makeMoveAndPrintPieceNumbers(int i,int j,char currentPlayer,ArrayList<brack>bracketed){
        grid[i][j]=currentPlayer;
        //brackented required
        for(brack bracket:bracketed){
            int subI=i,subJ=j;
            for (int t=0;t<bracket.times;t++){
                subI+=bracket.mov[0];
                subJ+=bracket.mov[1];
                grid[subI][subJ]=currentPlayer;
            }
        }
        //count
        int black=0,white=0;
        for(int iG=0;iG<8;iG++){
            for(int jG=0;jG<8;jG++){
                if(grid[iG][jG]=='W')
                    white++;
                else if(grid[iG][jG]=='B')
                    black++;
            }
        }
        System.out.printf("Black - %s%d White - %s%d\n",black<10?" ":"",black,white<10?" ":"",white);
    }
    static Scanner s = new Scanner(System.in);
    public static void main(String[]args){
        int t=Integer.parseInt(s.nextLine());
        for(int cs=0;cs<t;cs++){
            if(cs>0)
                System.out.printf("\n");
            for(int i=0;i<8;i++){
                String line=s.nextLine();
                for(int j=0;j<8;j++)
                    grid[i][j]=line.charAt(j);
            }
            char currentPlayer=s.nextLine().charAt(0);
            while(true){
                String command=s.nextLine();
                if(command.charAt(0)=='L')
                    listPossibleMoves(currentPlayer);
                else if(command.charAt(0)=='M'){
                    int i=command.charAt(1)-'0'-1,j=command.charAt(2)-'0'-1;
                    ArrayList<brack>bracketed=getBracketed(currentPlayer,i,j);
                    if(bracketed.size()==0){
                        currentPlayer=nextPlayer(currentPlayer);
                        bracketed=getBracketed(currentPlayer,i,j);
                    }
                    makeMoveAndPrintPieceNumbers(i,j,currentPlayer,bracketed);
                    currentPlayer=nextPlayer(currentPlayer);
                }else{
                    //print grid
                    for(int i=0;i<8;i++){
                        for(int j=0;j<8;j++)
                            System.out.printf("%c",grid[i][j]);
                        System.out.printf("\n");
                    }
                    break;
                }
            }
        }
    }
}