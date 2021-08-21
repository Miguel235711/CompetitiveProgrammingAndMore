#include <bits/stdc++.h>
#define lim 100008


using namespace std;



struct section{
    int g;
    int a;
    int b;
};
int memo[lim];
section river[lim];
int n,ans=0;


/*int f(int i){
    if(memo[i]!=-1)
        return memo[i];
    int _maxi = 0 ;
    for(int aIt = river[i].a; aIt<=river[i].b;aIt++){
        if(aIt+i>=n)
            break;
        _maxi = max(_maxi, f(i+aIt));
    }
    return memo[i] = _maxi+river[i].g;
}*/

///use bit
int BIT[lim];

int magic(int x ) {
    return x&-x;
}
int maxQuery(int l, int r){
    int ans = 0 ;
    while(r>=l){
        int nextR = r - magic(r);
        if(nextR+1>=l){
            ans=max(ans,BIT[r]);
            r = nextR;
        }else{
            ans = max(ans,memo[r]);
            r --;
        }
    }
    return ans;
}
void addToMax(int i, int x){
    while(i<=n){
        BIT[i]= max(BIT[i],x);
        i+=magic(i);
    }
}
void dp(){
    for(int i = n ; i ; i --){
        int l = i+river[i].a, r = min(n,i+river[i].b);
        int queryAns = l <= n ? maxQuery(l,r) : 0;
        memo[i] = river[i].g + queryAns ;
        addToMax(i,memo[i]);
        ans = max(ans,memo[i]);
    }
}
int main(){
    cin>>n;
    //memset(memo,-1,sizeof(memo));
    for(int i=1; i<=n; i++){
        cin >> river[i].g;
        cin >> river[i].a;
        cin >> river[i].b;
    }
    /*int ans = 0 ; 
    for(int i = 0 ; i < n ; i ++)
        ans = max(f(i),ans);*/
    //cout << f(0) << "\n";
    dp();
    cout << ans << "\n";
    return 0;
}