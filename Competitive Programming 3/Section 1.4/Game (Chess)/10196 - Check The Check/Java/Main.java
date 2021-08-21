import java.util.Scanner;
import java.util.HashMap;

public class Main{
    static Scanner s = new Scanner(System.in);
    static char[][] map = new char[12][12];
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
    static boolean attacks(int i,int j,Config conf, char objective){
        for(int mov = 0 ; mov < movs[conf.movIndex].length; mov ++){
            int iN=i,jN=j;
            for(iN+=movs[conf.movIndex][mov][0], jN+=movs[conf.movIndex][mov][1]; map[iN][jN]=='.' ; iN+=movs[conf.movIndex][mov][0], jN += movs[conf.movIndex][mov][1]){
                //System.out.printf("i=%d j=%d\n",iN,jN);
                if(!conf.isN)
                    break;
            }
            if(map[iN][jN]==objective)
                return true;
        }
        return false;
    }
    public static void main(String[]args){
        for(int cs = 1;true;cs++){
            boolean differentFromPoint = false;
            for(int i = 2 ; i <= 9 ; i ++){
                String line = s.next();
                for(int j = 2 ; j <= 9 ; j ++){
                    map[i][j] = line.charAt(j-2);
                    if(map[i][j]!='.'){
                        differentFromPoint=true;
                    }
                }
            }
            if(!differentFromPoint)
                break;
            String ans="no king is in check.";
            after:
            for(int i = 2 ; i <= 9 ; i ++){
                for(int j = 2 ; j <= 9 ; j ++){
                    if(map[i][j]!='.'){
                        char objective = Character.isLowerCase(map[i][j])?'K':'k';
                        char piece = map[i][j]!='p' && map[i][j]!='P' ? Character.toLowerCase(map[i][j]) : map[i][j];
                        if(attacks(i,j,getMovRow.get(piece),objective)){
                            ans=(objective=='K'?"white":"black")+" king is in check.";
                            break after;
                        }
                    }
                }
            }
            System.out.printf("Game #%d: %s\n",cs,ans);
        }
    }
}