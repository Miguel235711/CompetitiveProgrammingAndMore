import java.util.*;

public class Main{
    static Scanner sc = new Scanner(System.in);
    static int[][] dates={
        new int[]{21,19},
        new int[]{20,20},
        new int[]{21,20},
        new int[]{21,21},
        new int[]{22,21},
        new int[]{22,22},
        new int[]{23,21},
        new int[]{22,23},
        new int[]{24,23},
        new int[]{24,22},
        new int[]{23,22},
        new int[]{23,20}
    };
    static String[] zodiac={
        "aquarius",
        "pisces",
        "aries",
        "taurus",
        "gemini",
        "cancer",
        "leo",
        "virgo",
        "libra",
        "scorpio",
        "sagittarius",
        "capricorn"
    };
    static String getZodiac(GregorianCalendar gc){
        for(int i = 0 ; i < 12 ; i ++){
            int iP = (i+1)%12;
            int m = gc.get(Calendar.MONTH),d=gc.get(Calendar.DATE);
            if(m==i&&d>=dates[i][0] ||(m==iP)&&d<=dates[i][1]) 
                return zodiac[i];
        }
        return "";
    }
    public static void main(String[]args){
        int t = Integer.parseInt(sc.nextLine());
        for(int cs = 1 ; cs <= t ; cs++){
            String tk = sc.nextLine();
            int m = Integer.parseInt(tk.substring(0,2))-1,d =Integer.parseInt(tk.substring(2,4)), y= Integer.parseInt(tk.substring(4,8));
            GregorianCalendar gc = new GregorianCalendar(y, m, d);
            gc.add(Calendar.DATE, 280);
            System.out.printf("%d %02d/%02d/%04d %s\n",cs,gc.get(Calendar.MONTH)+1,gc.get(Calendar.DATE),gc.get(Calendar.YEAR),getZodiac(gc));
        }
    }
}