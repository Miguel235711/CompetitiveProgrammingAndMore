#include <bits/stdc++.h>
#define lose 101
#define extra 102

using namespace std;

int special[101],cell[5];
bool loseTurn[5];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<int>thrS;
    int x;
    while(cin>>x&&x)
        thrS.push_back(x);
    int n;
    while(cin>>n&&n){
        //init game set
        for(int i=1;i<101;i++)
            special[i]=i;
        //read game set
        int a,b;
        while(cin>>a>>b&&a)
            special[a]=b;
        while(cin>>x&&x){
            int absX=abs(x);
            special[absX] = x<0 ? lose : extra;
        }
        //simulate
        memset(loseTurn,false,sizeof(loseTurn));
        memset(cell,0,sizeof(cell));
        for(int throwI=0,player=0;;throwI++,player=(player+1)%n)
            if(loseTurn[player])
                loseTurn[player]=false;
            else{
                int dieNewCell = cell[player]+thrS[throwI];
                if(dieNewCell<101){
                    if(special[dieNewCell]<101)
                        cell[player]=special[dieNewCell];
                    if(special[cell[player]]==lose)
                        loseTurn[player]=true;
                    else if(special[cell[player]]==extra)
                        player=player?player-1:n-1;
                    if(cell[player]==100){
                        cout << player+1 << "\n";
                        break;
                    }
                }
            }
    }
    return 0;
}