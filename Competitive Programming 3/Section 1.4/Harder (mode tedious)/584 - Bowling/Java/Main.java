import java.util.stream.Stream;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Arrays;
import java.io.DataInputStream; 
import java.io.FileInputStream; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 

public class Main{
    static class Reader 
    { 
        final private int BUFFER_SIZE = 1 << 16; 
        private DataInputStream din; 
        private byte[] buffer; 
        private int bufferPointer, bytesRead; 
  
        public Reader() 
        { 
            din = new DataInputStream(System.in); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public Reader(String file_name) throws IOException 
        { 
            din = new DataInputStream(new FileInputStream(file_name)); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public String readLine() throws IOException 
        { 
            byte[] buf = new byte[64]; // line length 
            int cnt = 0, c; 
            while ((c = read()) != -1) 
            { 
                if (c == '\n') 
                    break; 
                buf[cnt++] = (byte) c; 
            } 
            return new String(buf, 0, cnt); 
        } 
  
        public int nextInt() throws IOException 
        { 
            int ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do
            { 
                ret = ret * 10 + c - '0'; 
            }  while ((c = read()) >= '0' && c <= '9'); 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public long nextLong() throws IOException 
        { 
            long ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public double nextDouble() throws IOException 
        { 
            double ret = 0, div = 1; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
  
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
  
            if (c == '.') 
            { 
                while ((c = read()) >= '0' && c <= '9') 
                { 
                    ret += (c - '0') / (div *= 10); 
                } 
            } 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        private void fillBuffer() throws IOException 
        { 
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
            if (bytesRead == -1) 
                buffer[0] = -1; 
        } 
  
        private byte read() throws IOException 
        { 
            if (bufferPointer == bytesRead) 
                fillBuffer(); 
            return buffer[bufferPointer++]; 
        } 
  
        public void close() throws IOException 
        { 
            if (din == null) 
                return; 
            din.close(); 
        } 
    } 
    static Reader s = new Reader();
    static ArrayList<Integer> arr;
    static HashMap<Character,Integer> mapSpecials = new HashMap<Character,Integer>(){{
        put('/',12);
        put('X',13);
    }};
    public static void main(String []args) throws IOException{
        while(true){
            String line = s.readLine();
            if(line.charAt(0)=='G')
                break;
            arr = new ArrayList<Integer>();
            for(int i=0;i<line.length();i++){
                char x = line.charAt(i);
                if(x!=' ')
                    arr.add(Character.isDigit(x) ? Character.getNumericValue(x) : mapSpecials.get(x));
            }
            int ans=0, count=0;
            boolean trail=false;
            for(int i=0;i<arr.size();i++){
                if((i+1==arr.size()||arr.get(i+1)!=12)&&count<10){
                    ans+=Math.min(10,arr.get(i));
                }
                int lim = count < 10 ? Math.min(i + Math.max(arr.get(i)-10,0) ,arr.size()) : i+1;
                if(trail||arr.get(i)==13){
                    count++;
                    trail=false;
                }else{
                    trail=true;
                }
                int before=-1;
                for(int next=i+1;next<lim;next++){
                    ans+=Math.min(10,arr.get(next));
                    if(arr.get(next)==12&&before!=-1){
                        ans-=before;
                    }
                    before=arr.get(next);
                }
            }
            System.out.printf("%d\n",ans);
        }
    }
}