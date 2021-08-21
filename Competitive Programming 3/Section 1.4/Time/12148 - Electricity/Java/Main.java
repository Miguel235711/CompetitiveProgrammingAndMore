import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[]args){
        int n;
        while((n=sc.nextInt())!=0){
            GregorianCalendar last=null;
            int lastC=0,ans=0,known=0;
            for(int i = 0 ; i < n ; i ++){
                int d = sc.nextInt() , m = sc.nextInt(), y = sc.nextInt(), c = sc.nextInt();
                GregorianCalendar gc = new GregorianCalendar(y, m - 1, d);
                GregorianCalendar aux = new GregorianCalendar(y,m - 1 ,d);
                gc.add(Calendar.DATE, -1);
                //System.out.printf("%d %d %d",gc.get(Calendar.YEAR),gc.get(Calendar.MONTH),gc.get(Calendar.YEAR))
                if(last!=null&&gc.get(Calendar.YEAR)==last.get(Calendar.YEAR)&&gc.get(Calendar.MONTH)==last.get(Calendar.MONTH)&&gc.get(Calendar.DATE)==last.get(Calendar.DATE)){
                    known++; 
                    ans+=c-lastC;
                }
                last = aux;
                lastC=c;
            }
            System.out.printf("%d %d\n",known,ans);
        }
    }
}