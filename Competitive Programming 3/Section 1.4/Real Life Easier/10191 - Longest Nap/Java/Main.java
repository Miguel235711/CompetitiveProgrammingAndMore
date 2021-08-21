import java.util.*;

public class Main{
    static Scanner sc = new Scanner(System.in);
    static class Appointment implements Comparable<Appointment>{
        public int b,e;
        public Appointment(int b,int e){
            this.b=b;
            this.e=e;
        }
        @Override
        public int compareTo(Appointment x){
            return b-x.b;
        }
    }
    static int getNormalized(String time){
        return (Integer.parseInt(time.substring(0,2))-10)*60+Integer.parseInt(time.substring(3,5));
    }
    public static void main(String[]args){
        for(int cs=1;sc.hasNext();cs++){
            Vector<Appointment> schedule = new Vector<Appointment>();
            for(int s = sc.nextInt(); s > 0 ; s --){
                String begin = sc.next(), end = sc.next();
                schedule.add(new Appointment(getNormalized(begin),getNormalized(end)));
                //System.out.printf("begin: %s end: %s\n",begin,end);
                sc.nextLine();
            }
            Collections.sort(schedule);
            schedule.add(new Appointment(480,480));
            int lastBeg = 0 , longestNap = 0 , bestBeg = 0, bestEnd = 0;
            for(int i = 0 ; i < schedule.size(); i++){
                if(schedule.get(i).b-lastBeg>longestNap){
                    longestNap = schedule.get(i).b-lastBeg;
                    bestBeg = lastBeg;
                    bestEnd = schedule.get(i).b;
                }
                lastBeg = schedule.get(i).e;
            }
            int duration = bestEnd-bestBeg;
            System.out.printf("Day #%d: the longest nap starts at %02d:%02d and will last for %s%s minutes.\n",cs,10+bestBeg/60,bestBeg%60,duration>59?duration/60+" hours and ":"",duration%60);
        }
    }
}