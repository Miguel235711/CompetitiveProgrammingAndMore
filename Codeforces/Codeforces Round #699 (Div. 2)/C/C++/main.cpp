#include<bits/stdc++.h>
 
#define mp make_pair 
#define pb push_back 
#define MAX(a, b) a = max(a, b) 
#define MIN(a, b) a = min(a, b) 
#define SQR(x) ((LL)(x) * (x)) 
#define RESET(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end() 
#define SORT(v) sort(ALL(v)) 
#define PERMUTE next_permutation
#define fi first 
#define se second
 
#define MOD 1000000009 //1E9+9
 
using namespace std;
 
typedef int64_t i64;
 
typedef pair<i64,i64> p64;
typedef vector<i64> v64;
typedef vector<p64>  v6464;
typedef vector < v64 > vv64;
 
typedef double dle;
typedef long double ldle;
 
typedef pair<int,int> pii; 
typedef vector<int> vi;
typedef vector< pii > vii;
typedef vector< vi > vvi;
 
 
typedef pair<string,string> pss;
typedef vector<string> vs;
typedef vector<pss> vss;
 
typedef pair<int,string> pis;
typedef vector<pis> vis;
typedef pair<string,int> psi;
typedef vector<psi> vsi;
 
typedef map<string,string> mss;
typedef map<int,string> mis;
typedef map<string,int> msi;
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n,m,ci,bi;
    cin >> t;
    while(t--){
        cin >> n >> m ; 
        vi a(n),ans(m);
        map<int,int> e;
        multimap<int,int> d;
        for(int i = 0 ; i < n ; i ++)
            cin >> a[i];
        for(int i = 0 ; i < n ; i ++){
            cin >> bi ;
            if (a[i]==bi) e[bi]=i; else d.insert({bi,i}); 
        }
        queue<int> toBeRepainted;
        auto repaintPendant = [&](int toPaint){
            for(;!toBeRepainted.empty();toBeRepainted.pop())
                ans[toBeRepainted.front()]=toPaint;
        };
        for(int i = 0 ; i < m ; i ++){
            cin >> ci;
            auto it = d.find(ci);
            if(it!=d.end()){
                d.erase(it),e.insert(*it);
                repaintPendant(it->second);
                ans[i]=it->second;
            }else if((it=e.find(ci))!=e.end()){
                repaintPendant(it->second);
                ans[i]=it->second;
            }else
                toBeRepainted.push(i);
        }
        if(d.empty() && toBeRepainted.empty()){
            cout << "YES\n";
            for(int i = 0 ; i < m ; i ++)
                cout << ans[i] + 1 << " ";
        }else
            cout << "NO";
        cout << "\n";
    }
    return 0;
}