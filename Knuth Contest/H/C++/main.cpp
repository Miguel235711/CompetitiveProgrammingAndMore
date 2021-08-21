#include<bits/stdc++.h>
using namespace std;
 
int bucket[100008];
 
int parity (int x){
    return x&1;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n,k,xi;
    cin >>t;
    while(t--){
        memset(bucket,0,sizeof(bucket));
        cin >> n >> k;
        int N = n,ans=0;
        for(int i = 1 ; i<=n;i++){
            cin >> xi;
            if(xi==i){
                N --;
            }else if(bucket[xi]==i){
                ans++;
                N-=2;
            }else{
                bucket[i]=xi;
            }
        }
        ans+=max(N-1,0);
        cout << ((ans<=k&&parity(k)==parity(ans))||(N>3&&ans+1<=k&&parity(k)==parity(ans+1))?"Yes":"No") << "\n";
    }
    return 0;
}