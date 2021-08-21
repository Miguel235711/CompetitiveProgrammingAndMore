import java.util.Scanner;
import java.util.HashMap;

public class Main{
    static Scanner s = new Scanner(System.in);
    static int correctPlaces,wrongPlaces,guess;
    static int getNumberOfDigits(int x){
        int i = 0;
        for(;x>0; i++,x/=10);
        return i;
    }
    static int getOnes(int n){
        int ans = 0 ;
        for(int i = 0 ; i < n ; i ++,ans+=1){
            ans*=10;
        }
        return ans;
    }
    static boolean isCorrect(int ans){
        int correctP=0,wrongP=0;
        HashMap<Integer,Integer> inAns = new HashMap<Integer,Integer>();
        for(int guessC = guess,ansC=ans;ansC>0;ansC/=10,guessC/=10){
            int digitA = ansC%10;
            if(digitA==guessC%10){
                correctP++;
                if(correctP>correctPlaces)
                    return false;
            }else{
                if(inAns.containsKey(digitA)){
                    inAns.replace(digitA,inAns.get(digitA)+1);
                }else{
                    inAns.put(digitA,1);
                }
            }
        }
        for(int guessC=guess;ans>0;ans/=10,guessC/=10){
            int digitG = guessC % 10;
            if(digitG!=ans%10&&inAns.containsKey(digitG)){
                wrongP++;
                if(wrongP>wrongPlaces)
                    return false;
                int rep = inAns.get(digitG);
                if(rep==1)
                    inAns.remove(digitG);
                else
                    inAns.replace(digitG,rep-1);
            }
        }
        return  correctP == correctPlaces && wrongP == wrongPlaces;
    }
    static boolean noZeros(int x){
        for(;x>0;x/=10){
            if(x%10==0)
                return false;
        }
        return true;
    }
    public static void main(String[]args){
        for(int t = s.nextInt(); t > 0 ; t--){
            guess = s.nextInt();
            correctPlaces = s.nextInt();
            wrongPlaces = s.nextInt();
            int initial = getOnes(getNumberOfDigits(guess)), last = initial * 9+1,ans=0;
            for(;initial<last;initial++){
                if(noZeros(initial)&&isCorrect(initial)){
                    ans++;
                }
            }
            System.out.printf("%d\n",ans);
        }
    }
}