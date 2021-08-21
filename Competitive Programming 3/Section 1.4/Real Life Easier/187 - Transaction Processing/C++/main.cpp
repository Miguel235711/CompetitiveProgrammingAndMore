#include<bits/stdc++.h>

using namespace std;

map<int,string> accounts;
vector<pair<int,int> > transactionEntries; //<account,number>

void process(int sequenceNumber,int acum){
    cout << "*** Transaction " << sequenceNumber << " is out of balance ***\n";
    for(auto entry : transactionEntries){
        string name = accounts[entry.first];
        cout << entry.first << " " << name << string(30-name.size()+1,' ') << setw(10) << fixed << setprecision(2) << (float)entry.second/100 << "\n";
    } 
    cout << "999 Out of Balance" << string(17,' ') << setw(10) << fixed << setprecision(2) << (float)-acum/100 << "\n\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string line;
    while(getline(cin,line)&&line.substr(0,3)!="000"){
        int account = stoi(line.substr(0,3));
        accounts[account]=line.substr(3,line.size()-3);
    }
    int lastS=0,acum=0;
    while(getline(cin,line)&&line.substr(0,3)!="000"){
        int sequenceNumber = stoi(line.substr(0,3));
        if(lastS!=sequenceNumber){
            if(acum){
                process(lastS,acum);
                acum=0;
            }
            lastS = sequenceNumber;
            transactionEntries.clear();
        }
        int account = stoi(line.substr(3,3));
        int number = stoi(line.substr(6,line.size()-6));
        acum+=number;
        transactionEntries.push_back(make_pair(account,number));
    }
    if(acum)
        process(lastS,acum);
    return 0;
}