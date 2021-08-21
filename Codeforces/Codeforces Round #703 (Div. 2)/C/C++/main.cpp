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


int query(int l, int r){
    if(l==r)
        return -1;
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    cin >> l;
    return l;
}

int f(int l,int r){///returns the maximum of position
    int q = query(l,r);
    while(l+1<r){  
        //cout << "l: " << l << " r: " << r << "\n";  
        int mid = (l+r)>>1;
        if(q<=mid){
            int qL = query(l,mid);
            if(qL==q)
                r = mid,q = qL;
            else
                l = mid + 1,q = query(mid+1,r);  
        }else{
            int qR = query(mid+1,r);
            if(qR==q)
                l = mid+1,q = qR;
            else
                r = mid, q = query(l,mid);
        }
    }
    return q == l ? r : l;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n ; 
    cin >> n ; 
    int ans = f(1,n);
    cout << "! " << ans << "\n";
    cout.flush();
    return 0;
}