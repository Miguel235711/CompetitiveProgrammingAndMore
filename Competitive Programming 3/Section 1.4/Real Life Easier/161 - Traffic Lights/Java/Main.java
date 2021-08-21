import java.util.Scanner;
import java.util.Vector;
import java.util.Collections;

public class Main{
    static Scanner sc = new Scanner(System.in);
    static class pair implements Comparable<pair>{
        public int c,p;
        public pair(int c,int p){
            this.c=c;
            this.p=p;
        }
        @Override
        public int compareTo(pair other){
            return this.c-other.c;
        }
    }
    static final int limTime = 18001;
    public static void main(String[]args){
        int x=-1,lastX;
        while(true){
            Vector<pair> lights = new Vector<pair>();
            while(true){
                lastX = x;
                if((x=sc.nextInt())==0){
                    if(lastX==0)
                        return;
                    break;
                }
                lights.add(new pair(x,0));
            }
            //process lights
            Collections.sort(lights);
            //simulate by packs
            pair smallest = lights.get(0);
            outerFor:
            {
                for(int p = 2 ;smallest.c*p+1 <= limTime;p+=2){
                    int limT = Math.min(smallest.c*(p+1)-4,limTime+1);
                    for(int t = smallest.c*p+1;t<limT;t++){
                        boolean allInT = true;
                        for(int j = 1 ; j < lights.size(); j++){
                            for(;lights.get(j).c*(lights.get(j).p+1)-5<t;lights.get(j).p+=2);
                            if(t < lights.get(j).p*lights.get(j).c+1||t>(lights.get(j).p+1)*lights.get(j).c-5)
                                allInT = false;
                        }
                        if(allInT){
                            t--;
                            System.out.printf("%02d:%02d:%02d\n",t/3600,(t-t/3600*3600)/60,t%60);
                            break outerFor;
                        }
                    }
                }
                System.out.println("Signals fail to synchronise in 5 hours");
            }
            /*for(pair p:lights)
                System.out.printf("%d ",p.c);
            System.out.println();*/
        }
    }
}