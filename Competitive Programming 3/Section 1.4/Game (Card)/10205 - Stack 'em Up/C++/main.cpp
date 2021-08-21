#include <bits/stdc++.h>

using namespace std;

string toSuit[4]={"Clubs","Diamonds","Hearts","Spades"},toValue[4]={"Jack","Queen","King","Ace"},line;
int cards[2][52],shuffles[100][52],t,n;
void initialize(){
    for(int i = 0; i < 52;i++){
        cards[0][i]=i;
        cards[1][i]=0;
    }
}
string getValue(int card){
    card%=13;
    if(card<9)
        return to_string(card+2);
    return toValue[card-9];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    for(int cs = 0 ; cs < t ; cs++){
        if(cs>0)
            cout << "\n";
        cin >> n;
        initialize();
        for(int i = 0;i<n;i++)
            for(int j = 0 ; j < 52; j++){
                cin >> shuffles[i][j];
                shuffles[i][j]--;
            }
        cin.ignore();
        int shuf=1;
        for(;getline(cin,line)&&!line.empty();shuf=1-shuf){
            int k = stoi(line)-1;
            //shuffle
            for(int j=0;j<52;j++)
                cards[shuf][j]=cards[1-shuf][shuffles[k][j]];
        }
        //! shuf has the answer
        for(int card:cards[1-shuf])
            cout << getValue(card) << " of " << toSuit[card/13] << "\n";
    }
    return 0;
}