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
    int t,n,m,bi;
    cin >> t;
    while(t--){
        cin >> n >> m ;
        vi a1,a(n);
        v64 a2; 
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i ++)
            cin >> a[i];
        for(int i = 0 ; i < n ; i ++){
            cin >> bi;
            if(bi==2)
                a2.pb(a[i]);
            else
                a1.pb(a[i]);
        }
        sort(a1.begin(),a1.end()),a1.pb(0),reverse(a1.begin(),a1.end());
        sort(a2.begin(),a2.end()),reverse(a2.begin(),a2.end());
        int s1=a1.size(),s2=a2.size();
        for(int i = 1 ; i < s2 ; i ++)
            a2[i]+=a2[i-1];
        i64 acum = 0 ; 
        for(int i = 0 ; i < s1; i ++){
            acum += a1[i];
            ///pure
            if(acum>=m){
                MIN(ans,i);
                break;
            }else if(s2){
                int l = 0, r = s2-1;
                while(l+1<r){
                    int mid = (l+r)/2;
                    if(acum+a2[mid]<m)
                        l = mid + 1;
                    else
                        r = mid;
                }
                ///answer is in r
                int ind = acum+a2[l]>=m ? l : r;
                if(acum+a2[ind]>=m)
                    MIN(ans,i+(ind+1)*2);
            }
        }
        cout << (ans==INT_MAX?-1:ans) << "\n";
    }
    return 0;
}