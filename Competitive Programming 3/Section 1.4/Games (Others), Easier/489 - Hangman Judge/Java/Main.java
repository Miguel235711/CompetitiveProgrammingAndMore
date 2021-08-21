import java.util.Scanner;
import java.util.HashSet;

public class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[]args){
        int round;
        while((round=s.nextInt())!=-1){
            HashSet<Character> objective = new HashSet<Character>(), visited = new HashSet<Character>(), wrong = new HashSet<Character>();
            System.out.printf("Round %d\n",round);
            String puzzle = s.next();
            for(int i = 0 ; i < puzzle.length(); i++){
                objective.add(puzzle.charAt(i));
            }
            String guess = s.next();
            for(int i = 0 ; i < guess.length();i++){
                if(objective.contains(guess.charAt(i))){
                    visited.add(guess.charAt(i));
                    if(visited.size()==objective.size())
                        break;
                }else{
                    wrong.add(guess.charAt(i));
                    if(wrong.size()>6){//loses
                        break;
                    }
                }
            }
            System.out.printf("You %s.\n",wrong.size()>6?"lose":(visited.size()==objective.size()?"win":"chickened out"));
        }
    }
}