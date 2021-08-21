import java.util.*;

public class Main{
    static class NoteEvent{
        public int note,code,m,b,t;
        public NoteEvent(int note, int code, int m,int b,int t){
            this.note=note;
            this.code=code;
            this.m=m;
            this.b=b;
            this.t=t;
        }
    }
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args){
        int n;
        while((n=sc.nextInt())!=-1){
            int finalN=n;
            Vector<NoteEvent> events = new Vector<NoteEvent>();
            HashMap<Integer,Integer> mapCodeToPositionInEvents = new HashMap<Integer,Integer>();
            for(int i = 0 ; i < n ; i ++){
                int code = sc.nextInt(), note = sc.nextInt(), m = sc.nextInt(), b = sc.nextInt(), t = sc.nextInt();
                //convert
                if(t>449){
                    t = 0;
                    //especial case, increment to next beat and/or measure
                    if(b==4){
                        b=1;
                        m++;
                    }else   
                        b++;
                }else
                    t=(t+30)/60*60%480;
                NoteEvent newEvent = new NoteEvent(note,code,m,b,t);
                if(code==1){
                    //push code
                    mapCodeToPositionInEvents.put(note,events.size());
                    //... missing push to vector
                }else{
                    //pop code
                    int positionInVector = mapCodeToPositionInEvents.get(note);
                    NoteEvent openedBef = events.get(positionInVector);
                    if(openedBef.m==newEvent.m&&openedBef.b==newEvent.b&&openedBef.t==newEvent.t){
                        events.get(positionInVector).m=newEvent.m=-1;//filter out both
                        finalN-=2;
                    }
                }
                events.add(newEvent);
            }
            System.out.println(finalN);
            for(NoteEvent event: events){
                if(event.m!=-1)
                    System.out.printf("%d %d %d %d %d\n",event.code,event.note,event.m,event.b,event.t);
            }
        }
        System.out.println("-1");
    }
}