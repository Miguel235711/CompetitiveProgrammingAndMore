#include <bits/stdc++.h>

using namespace std;

map<char,int> mapFromDirToInt = {
    make_pair('S',0),
    make_pair('W',1),
    make_pair('N',2),
    make_pair('E',3)
};
map<char,int> mapFromSuitToInt = {
    make_pair('C',0),
    make_pair('D',1),
    make_pair('S',2),
    make_pair('H',3)
};
map<char,int> rankToInt = {
    make_pair('T',8),
    make_pair('J',9),
    make_pair('Q',10),
    make_pair('K',11),
    make_pair('A',12)
};
char mapFromIntToSuit[4] = {'S','W','N','E'};
int offsetChar(char x){
    if(isdigit(x))
        return x-'2';
    return rankToInt[x];
}
int toIndex(string card){
    return mapFromSuitToInt[card[0]]*13 + offsetChar(card[1]);
}
vector<string> personCards[4];
void initialize(){
    for(int i = 0 ; i < 4 ; i ++)
        personCards[i].clear();
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    char directionDealer;
    string line;
    while(cin >> directionDealer,directionDealer!='#'){
        cin.ignore();
        initialize();
        for(int person=(mapFromDirToInt[directionDealer]+1)%4,lC=0; lC<2;lC++){
            getline(cin,line);
            //cout << "line: " << line << "\n";
            for(int i = 0 ; i < line.size(); i +=2,person=(person+1)%4){
                personCards[person].push_back(line.substr(i,2));
            }
        }
        for(int i = 0 ; i < 4 ; i ++){
            sort(personCards[i].begin(),personCards[i].end(),[](string a,string b){return toIndex(a) < toIndex(b);});
            cout << mapFromIntToSuit[i] << ":";
            for(string card: personCards[i])
                cout << " " << card;
            cout << "\n";
        }
    }
    return 0;
}