import java.util.Scanner;

public class Main{
    static Scanner s = new Scanner(System.in);
    static int[] byteArray;
    public static void main(String[] args){
        int t = Integer.parseInt(s.nextLine());
        for(int cs = 1 ; cs <= t ; cs++){
            String sequence = s.nextLine();
            byteArray = new int[100];
            int pointer = 0 ; 
            for(int i = 0 ; i < sequence.length(); i++){
                if(sequence.charAt(i)=='>'){
                    pointer=(pointer+1)%100;
                }else if(sequence.charAt(i)=='<'){
                    pointer--;
                    if(pointer<0){
                        pointer=99;
                    }
                }else if(sequence.charAt(i)=='+'){
                    byteArray[pointer]=(byteArray[pointer]+1)%256;
                }else if(sequence.charAt(i)=='-'){
                    byteArray[pointer]--;
                    if(byteArray[pointer]<0){
                        byteArray[pointer]=255;
                    }
                }
            }
            System.out.printf("Case %d:",cs);
            for(int i = 0 ; i < 100 ; i ++){
                System.out.printf(" %02X",byteArray[i]);
            }
            System.out.printf("\n");
        }
    }
}