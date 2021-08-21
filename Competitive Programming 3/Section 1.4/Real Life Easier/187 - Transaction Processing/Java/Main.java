import java.util.*;

public class Main{
    static HashMap<Integer,String> accounts = new HashMap<Integer,String>();
    static class Entry{
        public int account,number;
        public Entry(int account,int number){
            this.account=account;
            this.number=number;
        }
    }
    static Vector<Entry> transactionEntries = new Vector<Entry>();
    static void process(int sequenceNumber,int acum){
        System.out.printf("*** Transaction %d is out of balance ***\n",sequenceNumber);
        for(Entry entry: transactionEntries){
            String name = accounts.get(entry.account);
            String amountS = String.format("%.2f",(float)entry.number/100);
            System.out.printf("%d %s%s%s\n",entry.account,name,new String(new char[30-name.length()+11-amountS.length()]).replace('\0',' '),amountS);
        }
        String amountS = String.format("%.2f",(float)-acum/100);
        System.out.printf("999 Out of Balance%s%s\n\n",new String(new char[27-amountS.length()]).replace('\0',' '),amountS);
    }
    static Scanner sc = new Scanner(System.in);
    public static void main(String[]args){
        String line;
        while(!(line = sc.nextLine()).substring(0,3).equals("000")){
            int account = Integer.parseInt(line.substring(0,3));
            accounts.put(account,line.substring(3,line.length()));
        }
        int lastS=0,acum=0;
        while(!(line = sc.nextLine()).substring(0,3).equals("000")){
            int sequenceNumber = Integer.parseInt(line.substring(0,3));
            if(lastS!=sequenceNumber){
                if(acum!=0){
                    process(lastS,acum);
                    acum=0;
                }
                lastS = sequenceNumber;
                transactionEntries.clear();
            }
            int account = Integer.parseInt(line.substring(3,6));
            int number = Integer.parseInt(line.substring(6,line.length()).trim());
            acum += number;
            transactionEntries.add(new Entry(account,number));
        }
        if(acum!=0)
            process(lastS,acum);
    }
}