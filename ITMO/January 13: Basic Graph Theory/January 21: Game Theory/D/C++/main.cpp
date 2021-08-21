#include<bits/stdc++.h>
#define maxL 100008


using namespace std;

int memo[maxL][3],a[maxL],n;

int invert(int x){
    return x == 2 ? 1 : 2;
}

int f(int,int);

void proc(int i,int j,int nP, int & winner,int player){
    //cout << "player: " << player << " nP:  " << nP << "\n";
    if(a[j]>a[i]){
        int x = f(j,nP);
        if(x==player)
            winner = player;
    }
}

int f(int i,int player){
    if(memo[i][player])
        return memo[i][player];
    int nP = invert(player);
    int winner = nP;
    //cout << "i: " << i << "\n";
    for(int j = i - a[i] ; j > -1 ; j -= a[i])  
        proc(i,j,nP,winner,player);   
    for(int j = i + a[i] ; j < n ; j += a[i])
        proc(i,j,nP,winner,player);
    return memo[i][player] = winner;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; i ++)   
        cin >> a[i];
    for(int i = 0 ; i < n ; i ++)
        cout << (f(i,1) == 1 ? 'A' : 'B');
    cout << "\n";
    return 0;
}