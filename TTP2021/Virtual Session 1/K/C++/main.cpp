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

int calc(vi & a,vi & b){
    vi inPlace; /// bound to min(a.size(),b.size())
    size_t j = 0;
    int ans=0; 
    for(size_t i = 0 ; i < a.size() ; i ++){
        for(;j<b.size()&&b[j]<a[i];j++);
        if(j<b.size()&&b[j]==a[i])
            inPlace.push_back(b[j]);
    }
    /*cout << "inPlace:\n";
    for(int i = 0 ; i < inPlace.size(); i ++)
        cout << inPlace[i] << " ";
    cout << "\n";*/
    ///calc
    j = 0 ;
    for(auto it = b.begin() ; it != b.end() ; it ++){
        for(;j<a.size()&&a[j]<=*it;j++);
        int delta = *it+j;
        ///->R
        auto nextEAfterP = lower_bound(b.begin(),b.end(),delta);
        auto inPlaceAfter = lower_bound(inPlace.begin(),inPlace.end(),delta);
        MAX(ans,(int)distance(it,nextEAfterP)+(int)distance(inPlaceAfter,inPlace.end()));
        ///->L
        if(j){
            auto beforeP =  upper_bound(b.begin(),b.end(),*it-j);
            inPlaceAfter = upper_bound(inPlace.begin(),inPlace.end(),*it);
            MAX(ans,(int)distance(beforeP,it)+1+(int)distance(inPlaceAfter,inPlace.end()));
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m,t,xi;
    cin >> t ;
    while(t--){
        cin >> n >> m ;  
        vi nA,pA,nB,pB;
        for(int i = 0 ; i < n ; i ++)
            cin >> xi , xi<0 ? nA.push_back(-xi) : pA.push_back(xi);
        for(int i = 0 ; i < m ; i ++)
            cin >> xi , xi<0 ? nB.push_back(-xi) : pB.push_back(xi);
        reverse(nA.begin(),nA.end());
        reverse(nB.begin(),nB.end());
        cout << calc(nA,nB)+calc(pA,pB) << "\n";
    }
    return 0;
}