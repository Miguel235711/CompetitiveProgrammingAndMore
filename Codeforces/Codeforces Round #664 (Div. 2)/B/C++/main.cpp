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
 
i64 getMult(int i,int j,vector<i64> & a){
    i64 ans=1;
    for(;i<j;i++)
        ans*=(i64)a[i];
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    i64 t,n,x;
    cin >> t;
    while(t--){
        vector<i64> positives, negatives; 
        cin >> n ; 
        for(i64 i = 0 ; i < n ; i ++){
            cin >> x;
            if(x<0)
                negatives.push_back(x);
            else
                positives.push_back(x);
        }
        SORT(positives);
        SORT(negatives);
        i64 pSz = positives.size(), nSz = negatives.size();
        i64 ans = LLONG_MIN;
        ///only positives
        if(pSz>4){
            MAX(ans,getMult(pSz-5,pSz,positives)); 
        }
        ///only negatives
        if(nSz>4){
            MAX(ans,getMult(nSz-5,nSz,negatives));
        }
        ///smallest negatives with biggest positives
        for(i64 i = 2 ; nSz>=i && i < 5 ; i +=2){
            if(pSz>=5-i){
                MAX(ans,getMult(0,i,negatives)*getMult(pSz-5+i,pSz,positives));
            }
        }
        ///biggest negatives with smallest positives
        i64 lim =max(nSz-4,(i64)-1);
        for(i64 i =nSz - 1 ; i > lim ; i -=2){
            if(pSz>=(nSz-i)){
                MAX(ans,getMult(i,nSz,negatives)*getMult(0,5-nSz+i,positives));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}