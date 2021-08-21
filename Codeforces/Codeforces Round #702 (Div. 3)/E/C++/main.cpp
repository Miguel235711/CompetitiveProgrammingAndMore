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
#define boundLim 200008

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

pair<int,int> a[boundLim];
int64_t acum[boundLim];
int n;

bool possible(int i){
    int64_t sum = acum[i++];
    for(;i <= n ; i ++){
        if(sum<a[i].fi)
            return false;
        sum+=a[i].fi;
    }
    return true;
}

int bin(){
    int l = 1 , r = n ; 
    while(l+1<r){
        int mid = (l+r)/2;
        if(possible(mid))
            r = mid;
        else 
            l = mid + 1 ; 
    }
    return possible(l) ? l : r;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t ; 
    while(t--){
        cin >> n ;  
        for(int i = 1 ; i <= n ; i ++)
            cin >> a[i].first,a[i].second = i;
        sort(a+1,a+n+1);
        for(int i = 1 ; i <= n ; i ++){
            acum[i] = acum[i-1]+a[i].first;
        }
        vector<int> ans;
        //cout << "possible(1): " << possible(1) << "\n";
        for(int i = bin(); i <= n ; i ++){
            ans.push_back(a[i].second); 
        }
        sort(ans.begin(),ans.end());
        cout << ans.size() << "\n";
        for(size_t i = 0 ; i < ans.size() ; i ++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}