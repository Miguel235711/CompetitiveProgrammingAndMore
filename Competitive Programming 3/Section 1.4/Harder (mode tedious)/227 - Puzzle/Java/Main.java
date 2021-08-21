import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    static Scanner s = new Scanner(System.in);
    static char[][] grid=new char[5][5];
    static HashMap<Character,ArrayList<Integer>> getAdjacent= new HashMap<Character,ArrayList<Integer>>(){{
        put('L',new ArrayList<Integer>(Arrays.asList(0,-1)));
        put('R',new ArrayList<Integer>(Arrays.asList(0,1)));
        put('B',new ArrayList<Integer>(Arrays.asList(1,0)));
        put('A',new ArrayList<Integer>(Arrays.asList(-1,0)));
    }};
    static boolean valid(int i,int j){
        return i>-1&&j>-1&&i<5&&j<5;
    }
    static int iE, jE;
    static boolean successfull(char command){
        ArrayList<Integer> adjMov=getAdjacent.get(command);
        if(adjMov==null)
            return false;
        int newIE=iE+adjMov.get(0),newJE=jE+adjMov.get(1);
        if(!valid(newIE,newJE))
            return false;
        //make move
        grid[iE][jE]=grid[newIE][newJE];
        grid[newIE][newJE]=' ';
        iE=newIE;
        jE=newJE;
        return true;
    }
    public static void main(String[]args){
        for(int cs=1;true;cs++){
            for(int i=0;i<5;i++){
                String line = s.nextLine();
                if(line.charAt(0)=='Z')
                    return;
                for(int j=0;j<5;j++){
                    grid[i][j]=line.charAt(j);
                    if(grid[i][j]==' '){
                        iE=i;
                        jE=j;
                    }
                }
            }
            System.out.printf("%sPuzzle #%d:\n",cs>1?"\n":"",cs);
            boolean possible=true;
            commandsBlock:
            while(true){
                String commands=s.nextLine();
                for(int i=0;i<commands.length();i++){
                    if(commands.charAt(i)=='0')
                        break commandsBlock;
                    else if(possible&&!successfull(commands.charAt(i))){
                        possible=false;
                        System.out.printf("This puzzle has no final configuration.\n");
                    }
                }
            }
            if(possible)
                for(int i=0;i<5;i++){
                    for(int j=0;j<5;j++)
                        System.out.printf("%s%c",j>0?" ":"",grid[i][j]);
                    System.out.printf("\n");
                }
        }
    }
}