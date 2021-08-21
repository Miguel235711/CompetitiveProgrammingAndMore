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

int t,n,m,x;

int findI(const v64 & sum,int x){
    ///binary search to find fist sumIm[i] >= toReach
    int l = 1 , r = n;
    while(l+1<r){
        int mid = (l+r)/2;
        if(sum[mid]<x)
            l = mid + 1;
        else
            r = mid;
    }
    return sum[l] >= x ? l : (sum[r]>=x?r:-1);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    while(t--){
        cin >> n >> m;
        v64 sumIm(n+1);
        i64 sum=0;
        for(int i = 1 ; i <= n ; i ++){
            cin >> x;
            sum+=x;
            sumIm[i] = max(sum,sumIm[i-1]);
        }
        //cout << "sumIm[n]: " << sumIm[n] << "\n";
        while(m--){
            cin >> x;
            int especialI = findI(sumIm,x);
            if(especialI!=-1){
                cout << especialI -1 << " ";
                continue;
            }
            if(sum<=0){
                cout << "-1 ";
                continue;
            } 
            int completes = (x-1)/sum;
            x -= completes * sum;
            cout << (i64) findI(sumIm,x) + (i64) completes * n - 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}