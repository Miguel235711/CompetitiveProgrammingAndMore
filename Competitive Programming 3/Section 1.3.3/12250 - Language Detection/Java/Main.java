import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class Main {
    static Map<String, String> myMap = new HashMap<String, String>() {{
        put("HELLO","ENGLISH");
        put("HOLA","SPANISH");
        put("HALLO","GERMAN");
        put("BONJOUR","FRENCH");
        put("CIAO","ITALIAN");
        put("ZDRAVSTVUJTE","RUSSIAN");      
    }};
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int cs = 1;
        while(s.hasNextLine()){
            String line = s.nextLine();
            if(line.charAt(0)!='#'){
                String value = myMap.get(line);
                System.out.printf("Case %d: %s\n",cs++,value == null ? "UNKNOWN" : value);
            }
        }
    }
}