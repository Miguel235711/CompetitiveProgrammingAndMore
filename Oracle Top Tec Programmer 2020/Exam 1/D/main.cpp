#include<bits/stdc++.h>

using namespace std;

int n,scoreEnemy,amountOfMe;
bool x;
bool me[102];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ; 
    for(int i = 0 ; i < n ; i ++){
        cin >> me[i] ; 
    }
    for(int i = 0 ; i < n ; i ++){
        cin >> x ; 
        if(!me[i]&&x){
            scoreEnemy++;
        }else if(me[i]&&!x){
            amountOfMe++;
        }
    }
    scoreEnemy++;
    if(amountOfMe){
        cout << scoreEnemy/amountOfMe +(scoreEnemy%amountOfMe?1:0);
    }else{
        cout << "-1";
    }
    cout << "\n";
    return 0 ;
}