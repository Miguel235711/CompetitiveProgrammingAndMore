import java.util.Scanner;
import java.util.HashMap;
import java.util.HashSet;
import java.text.DecimalFormat;

public class Main {
    static Scanner s = new Scanner(System.in);
    static HashMap<String,Integer> mapToPoints = new HashMap<String,Integer>(){{
        put("king",9);
        put("queen",7);
        put("knight",5);
        put("jack",3);
    }};
    static HashSet<String> mapToPointsOudlers = new HashSet<String>(){{
        add("fool");
        add("one of trumps");
        add("twenty-one of trumps");
    }};
    static int[] pointsToWin = {112,102,82,72};
    public static void main(String[]args){
        int t = Integer.parseInt(s.nextLine());
        for(int cs=1;cs<=t;cs++){
            if(cs>1)
                System.out.printf("\n");
            System.out.printf("Hand #%d\n",cs);
            int points=0,oudlers=0;
            for(int n = Integer.parseInt(s.nextLine());n > 0;n--){
                String card=s.nextLine();
                String begCard = card.split(" ")[0];
                //check if it is oudler
                if(mapToPointsOudlers.contains(card)){
                    points+=9;
                    oudlers++;
                }else{
                    //sum points
                    Integer p = mapToPoints.get(begCard);
                    if(p==null){
                        points++;
                    }else{
                        points+=p;
                    }
                }
            }
            int dif = Math.abs(pointsToWin[oudlers]-points);
            DecimalFormat format = new DecimalFormat("0.##");
            System.out.printf("Game %s by %s point(s).\n",points<pointsToWin[oudlers]?"lost":"won",format.format((float)dif/2));
        }
    }
}