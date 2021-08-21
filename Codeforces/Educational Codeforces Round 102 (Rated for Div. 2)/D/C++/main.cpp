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

int cToI (char x){
    return x=='+'?1:-1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n,m,li,ri;
    string s;
    cin >> t ; 
    while(t--){
        cin >> n >> m ; 
        cin >> s ;
        vi sums(n+1),maxPre(n+1),maxSuf(n+2),minPre(n+1),minSuf(n+2);
        maxPre[0]=maxSuf[n+1]=-n;
        minPre[0]=minSuf[n+1]=n;
        for(int i = 1 ; i <= n ; i ++){
            sums[i]=cToI(s[i-1])+sums[i-1];
            maxPre[i] = max(sums[i],maxPre[i-1]);
            minPre[i] = min(sums[i],minPre[i-1]);
        }
        for(int i = n ; i ; i --){
            maxSuf[i] = max(maxSuf[i+1],sums[i]);
            minSuf[i] = min(minSuf[i+1],sums[i]);
        }
        /*cout << "maxPre:\n";
        for(int i = 0 ; i <= n ; i ++)
            cout << maxPre[i] << " ";
        cout << "\n";
        cout << "minPre:\n";
        for(int i = 0 ; i <= n ; i ++)
            cout << minPre[i] << " ";
        cout << "\n";
        cout << "maxSuf:\n";
        for(int i = 0 ; i <= n ; i ++)
            cout << maxSuf[i] << " ";
        cout << "\n";
        cout << "minSuf:\n";
        for(int i = 0 ; i <= n ; i ++)
            cout << minSuf[i] << " ";
        cout << "\n";*/
        ///process queries
        maxPre[0]=maxSuf[n+1]=minPre[0]=minSuf[n+1]=0;
        while(m--){
            cin >> li >> ri;
            int midS = sums[ri] - sums[li-1];
            int mx =  max(maxPre[li-1],ri < n ? maxSuf[ri+1] - midS : 0 ),mn = min(minPre[li-1], ri < n ? minSuf[ri+1] - midS:0);
            int absMx = abs(mx), absMn = abs(mn);
            //cout << "mx: " << mx  << " mn: " << mn << "\n"; 
            cout << (mx>=0&&mn<=0?absMx+absMn:max(absMx,absMn))+1 << "\n";
        }
    }
    return 0;
}