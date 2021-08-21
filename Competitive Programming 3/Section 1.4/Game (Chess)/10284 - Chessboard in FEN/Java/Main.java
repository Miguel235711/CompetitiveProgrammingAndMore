import java.util.Scanner;
import java.util.HashMap;

public class Main {
    static int[][][] movs = {
        {{1,-1},{1,1}},//black pawn (1)
        {{-1,-1},{-1,1}},//white pawn (1)
        {{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}}, // knight (1)
        {{1,1},{-1,-1},{-1,1},{1,-1}},//bishop (1..n)
        {{1,0},{-1,0},{0,1},{0,-1}}, // rook (1..n)
        {{1,1},{-1,-1},{-1,1},{1,-1},{1,0},{-1,0},{0,1},{0,-1}}//queen or king (special case [1..n and 1])
    };
    static class Config{
        int movIndex;
        boolean isN;
        public Config(int movIndex,boolean isN){
            this.movIndex = movIndex;
            this.isN=isN;
        }
    }
    static HashMap<Character,Config> getMovRow = new HashMap<Character,Config>(){{
        put('p',new Config(0,false));
        put('P',new Config(1,false));
        put('n',new Config(2,false));
        put('b',new Config(3,true));
        put('r',new Config(4,true));
        put('q',new Config(5,true));
        put('k',new Config(5,false));
    }};
    static char[][] map = new char[12][12];
    static Scanner s = new Scanner(System.in);
    static boolean[][] used;
    static int numberUsed = 0 ; 
    static void initialize(){
        used = new boolean[12][12];
        numberUsed = 0 ; 
    }
    static void visitCell(int i,int j){
        if(!used[i][j]){
            used[i][j]=true;
            numberUsed++;
        }
    }
    static void visAttacked(int i,int j,Config movRow){
        int sz = movs[movRow.movIndex].length;
        for(int mov = 0 ; mov < sz ;mov++){
            for(int iN = i+movs[movRow.movIndex][mov][0], jN = j+movs[movRow.movIndex][mov][1]; map[iN][jN]=='.'; iN+=movs[movRow.movIndex][mov][0],jN+=movs[movRow.movIndex][mov][1]){
                visitCell(iN,jN);
                if(!movRow.isN)
                    break;
            }
        }
    }
    public static void main(String[]args){
        while(s.hasNext()){
            initialize();
            String line = s.next();
            for(int i = 2,j=2,index=0; index < line.length() ;index++){
                char c = line.charAt(index);
                if(c=='/'){
                    j=2;
                    i++;
                }else if(Character.isDigit(c)){
                    for(int t = c-'0' ; t > 0 ; t--,j++){
                        map[i][j]='.';
                    }
                }else{
                    map[i][j++]=c;
                }
            }
            for(int i = 2 ; i < 10 ; i ++){
                for(int j = 2 ; j < 10 ; j++){
                    if(map[i][j]!='.'){
                        visitCell(i,j);
                        visAttacked(i,j,getMovRow.get(map[i][j]=='p'||map[i][j]=='P'?map[i][j]:Character.toLowerCase(map[i][j])));
                    }
                }
            }
            System.out.printf("%d\n",8*8-numberUsed);
        }
    }
}