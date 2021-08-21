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

int solve(vi & a,vi & b){
    ///precalc matched
    int j = b.size()-1;
    vi matchedB(b.size()*2+2);
    vi bestB(b.size()+1);
    vi maxContigousB(b.size()+1); 
    int maxContigousAcum = 1 ;
    maxContigousB[j]=maxContigousAcum;
    for(int i = (int)a.size() - 1 ; i > -1 ; i --){
        cout << "i: " << i << " a[i]: " << a[i] << "\n";
        for(;j>-1&&b[j]>a[i];j--){
            if(j+1==b.size() || b[j+1]!=b[j]+1)
                maxContigousAcum=1;
            else
                maxContigousAcum++;
            maxContigousB[j] = maxContigousAcum;
            if(!matchedB[j])
                matchedB[j]=matchedB[j+1];
        }
        cout << "j: " << j << " b[j]: " << b[j] << "\n";
        if(j>-1)
            matchedB[j]=matchedB[j+1] + (b[j]==a[i]);
        cout << "matchedB[j]: " << matchedB[j] << "\n";
    }
    ///calc
    cout << "matchedB\n";
    for(int i = 0 ; i < b.size(); i++ )
        cout << matchedB[i] << " ";
    cout << "\nmaxContigousB\n";
    for(int i = 0 ; i < b.size(); i++ )
        cout << maxContigousB[i] << " ";
    cout << "\n";
    j = 0;
    int ans = 0 ;
    for(size_t i = 0 ; i < a.size() ; i++){
        for(;j+1<b.size() && b[j]<a[i];j++);
        int maxMatchL = min((int)i+1,maxContigousB[j]);
        ans = max(ans,maxMatchL+matchedB[maxMatchL+j]);
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n,m,xi;
    cin >> t ;
    while(t--){
        cin >> n >> m;
        vi a1,b1,a2,b2;
        for(int i = 0 ; i < n ; i ++)
            cin >> xi , xi<0?a1.push_back(-xi):a2.push_back(xi);
        for(int i = 0 ; i < m ; i++)
            cin >> xi, xi<0?b1.push_back(-xi):b2.push_back(xi);
        sort(a1.begin(),a1.end());
        sort(b1.begin(),b1.end());
        cout << solve(a1,b1) + solve(a2,b2) << "\n";
    }
    return 0;
}