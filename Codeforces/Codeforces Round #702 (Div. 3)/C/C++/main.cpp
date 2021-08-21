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

int64_t cubed(int64_t x){
    return x*x*x;
}


bool isCubed(int64_t x){
    int l = 1 , r = 10000;
    while(l+1<r){
        int mid = (l+r)/2;
        int64_t mid3 = cubed(mid);
        if(mid3==x)
            return true;
        if(mid3<x)
            l = mid + 1; 
        else
            r = mid - 1;
    }
    return cubed(l)==x || cubed(r)==x;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    int64_t x; 
    cin >> t ; 
    while(t--){
        cin >> x ; 
        bool positive = false;
        for(int i = 1 ;; i++){
            int64_t i3 = cubed(i);
            if(i3>x)
                break;
            int64_t rest = x - i3 ; 
            if(rest>0 && isCubed(rest)){
                positive = true;
                break;
            }
        }
        cout << (positive ? "YES" : "NO") << "\n";
    }
    return 0;
}