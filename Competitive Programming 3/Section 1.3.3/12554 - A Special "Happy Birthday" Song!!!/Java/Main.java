import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    static String[] song={
        "Happy",
        "birthday",
        "to",
        "you"
    },people=new String[100];
    public static void main(String[]args){
        int n =  Integer.parseInt(s.nextLine());
        for(int i = 0 ; i < n ; i++){
            people[i]=new String(s.nextLine());
        }
        int lines = (int)Math.ceil((float)n/16)*16;
        for(int moment = 0 ; moment < lines ; moment++){
            System.out.printf("%s: %s\n",people[moment%n],moment%16!=11?song[moment%4]:"Rujia");
        }
    }
}