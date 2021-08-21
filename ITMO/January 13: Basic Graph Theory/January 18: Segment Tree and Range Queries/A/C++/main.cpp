#include <bits/stdc++.h>
#define maxL 1000008
#define maxL2 2000008

using namespace std;

int64_t a[maxL];
int64_t c[maxL2];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int64_t n,x,y;
    int64_t m,z,t;
    cin >> n >> x >> y >> a[1];
    cin >> m >> z >> t >> c[0];
    for(int64_t i = 2 ; i <= n ; i ++)
        a[i] = (a[i-1]*x + y) % 65536;//, cout << "a[i]: "<< a[i] << "\n"; 
    for(int64_t i = 2 ; i <= n ; i ++)
        a[i]+=a[i-1];
    int64_t m2 = m<<1;
    for(int64_t i = 1 ; i < m2 ; i ++)
        c[i] = (c[i-1]*z + t)% 1073741824;//
    for(int64_t i = 0 ; i < m2 ; i ++)
        c[i]%=n;//,cout << "c[i]: " << c[i] << "\n";
    int64_t ans = 0 ; 
    for(int64_t i = 0 ; i < m ; i ++){
        int64_t l = min(c[i*2],c[i*2+1]), r = max(c[i*2],c[i*2+1]);
        ans += a[r+1] - a[l];
    }
    cout << ans << "\n";
    return 0;
}