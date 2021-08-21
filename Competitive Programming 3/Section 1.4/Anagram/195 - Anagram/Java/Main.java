import java.util.Scanner;
import java.util.Arrays;

public class Main {
    static Scanner s = new Scanner(System.in);
    static char[] st;
    static boolean isLessThan(char a,char b){
        char aP = Character.toLowerCase(a) , bP = Character.toLowerCase(b);
        return aP == bP ? a < b : aP < bP;
    }
    static boolean next_permutation(){
        int i = st.length-1;
        for(;i != 0 && (isLessThan(st[i],st[i-1]) || st[i]==st[i-1]) ; i --);
        if(i==0)
            return false;
        //find first element greater than element with bin search
        char el = st[i-1];
        int l = i , r = st.length-1;
        while(l+1 < r){
            int mid = (l+r)>>1;
            if(isLessThan(st[mid],el) || st[mid]==el)
                r = mid - 1 ;
            else
                l = mid;
        }
        int swapPos = l;
        if(isLessThan(el,st[r]))
            swapPos=r;
        //swap with corresponding
        st[i-1]^=st[swapPos];
        st[swapPos]^=st[i-1];
        st[i-1]^=st[swapPos];
        //sort suffix by swapping
        for(int j = st.length-1 ; i < j ; i++,j--){
            st[i]^=st[j];
            st[j]^=st[i];
            st[i]^=st[j];
        }
        return true;
    }
    static int comparator(char a,char b){
        return isLessThan(a,b) ? -1 : (a == b ? 0 : 1);
    }
    public static void main(String[]args){
        for(int n = s.nextInt(); n>0 ; n--){
            st = s.next().toCharArray();
            Arrays.sort(st,new Comparator<Character>(){
                @Override
                public int compare(Character a,Character b){
                    return comparator(a,b);
                }
            });
            do{
                System.out.println(st);
            }while(next_permutation());
        }
    }
}