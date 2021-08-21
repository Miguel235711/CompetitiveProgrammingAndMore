import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 

public class Main2 {
    static class Reader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public Reader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 
    static int difPositions(int orig,int dest, boolean clockwise){
        if(clockwise){
            //swap
            orig^=dest;
            dest^=orig;
            orig^=dest;
        }
        return dest < orig ? orig-dest : 40 - dest + orig;
    }

    public static void main(String[] args)throws IOException {
        Reader s = new Reader ();
        while(true){
            int init = s.nextInt(), a = s.nextInt(), b = s.nextInt(), c = s.nextInt();
            if(init==0&&a==0&&b==0&&c==0){
                break;
            }
            System.out.printf("%d\n",(difPositions(init,a,false) + difPositions(a,b,true) + difPositions(b,c,false)) * 9 + 1080);
        }
    }
}