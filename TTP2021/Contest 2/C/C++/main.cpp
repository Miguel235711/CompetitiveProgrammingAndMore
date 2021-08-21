#include<vector>
#include<utility>
#include<string>
#include<map>
#include<set>
#include<math.h>
#include<iostream>
#include<climits>
#include<cstring>

using namespace std;


int m[18][18],s[18][5008][108],vF,n;

long long int f(int p,int v,int lim){
    //cout << "lim: " << lim << "\n";
    if(v==vF&&p==0)
        return 0;
    if(!lim)
        return INT_MAX;
    if(s[p][v][lim]!=-1)
        return s[p][v][lim];
    long long int ans = INT_MAX;
    for(int i = 0,vP = v; i <= n ; i ++,vP>>=1)
        ans=min(ans,f(i,v|(1<<i),lim-1)+m[p][i]);
    return s[p][v][lim]=ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>n,n){
        vF = (1<<(n+1))-1;
        memset(s,-1,sizeof(s));
        for(int i = 0 ; i <= n ; i ++){
            for(int j = 0 ; j <= n ; j++)
                cin >> m[i][j];
        }
        cout << f(0,1,(n+1)*(n+1)) << "\n";
    }
    return 0;
}