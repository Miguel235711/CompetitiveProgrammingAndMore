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
    int t,n,x;
    cin >> t;
    while(t--){
        map<int,int> bucket;
        cin >> n ;
        int64_t ans = n ;  
        for(int i = 0 ; i < n ; i ++){
           cin >> x ; 
           bucket[x]++; 
        }
        vector<int> sorted;
        for(auto it = bucket.begin(); it!=bucket.end(); it++){
            sorted.push_back(it->second);
        }
        sort(sorted.begin(),sorted.end());
        n = sorted.size();
        ///precalc
        int64_t costR = 0 ; 
        /*for(int i = 0 ; i < n ; i ++)
            cout << "sorted[i]: " << sorted[i] << "\n"; */
        for(int i = 1 ; i < n ; i ++)
            costR += sorted[i]-sorted[0];
        int64_t acumS = 0;
        for(int i = 0 ; i < n ; i ++){
            //cout << "acumS: " << acumS << " costR: " << costR << "\n";
            if(acumS+costR<ans)
                ans = acumS+costR;
            acumS += sorted[i];
            if(i+1<n)
                costR -= (sorted[i+1]-sorted[i]) * (n-1-i);
        }
        cout << ans << "\n";
    }
    return 0;
}