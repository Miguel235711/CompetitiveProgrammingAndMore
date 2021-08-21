#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    while(cin>>n>>m,n||m){
        int maxAns=0;
        if(n==1||m==1){
            maxAns = max(n,m);
        }else if (n==2 || m ==2){
            int l = max(n,m);
            int localAns = 0;
            localAns = (l+1)/4;
            localAns*=2;
            if(l%4==1 || l%4==2){
                localAns += l%4;
            }
            maxAns = localAns*2;
        }else{
            maxAns = ((n*m)+1)/2;
        }
        cout << maxAns << " knights may be placed on a " << n << " row " << m << " column board.\n";
    }
    return 0;
}