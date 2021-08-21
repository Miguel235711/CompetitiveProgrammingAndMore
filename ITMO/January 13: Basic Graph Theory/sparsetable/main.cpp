#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin >> n >> m;
    int bp = log2(n);
    vector<vector<int> > sparse(n,vector<int>(bp));
    cin >> sparse[0][0];
    int u , v;
    cin >> u >> v ;
    if(u>v)
        swap(u,v);
    ///u[0] <= v[0]
    for(int i = 1 ; i < n; ++i)
        sparse[i][0] = 23*sparse[i-1][0] % 16714589;
    ///build sparse table 
    for(int k = 1 ; k < bp; ++k){
        int lim = n -(1<<k)+1;
        for(int i = 0 ; i < lim ;++i)
            sparse[i][k]=min(sparse[i][k-1],sparse[i+(1<<(k-1))][k-1]);
    }
    ///precalculate power
    vector<int> maxp(n+1);
    for(int i = 2 ; i < maxp.size() ; i++)
        maxp[i] = maxp[i>>1]+1;
    ///& captures all in scope variables as references
    ///[&](int,int){}
    auto get_min = [&](int l,int r){ /// r exclusive
        int k = maxp[r-l];
        return min(sparse[l][k],sparse[r-(1<<k)][k]);
    };
    int lastRi = get_min(u,v-1);
    cout << lastRi << " ";
    for(int i = 1 ; i < m ; i ++){
        u = (17*u+751+lastRi+(i+1)*2)%n+1,
        v = (13*v+593+lastRi+(i+1)*5)%n+1;
        if(u>v)
            swap(u,v);
        ///u[0] <= v[0]
        lastRi = get_min(u,v-1);
        cout << lastRi << " ";
    }
    cout << "\n";
    return 0;
}