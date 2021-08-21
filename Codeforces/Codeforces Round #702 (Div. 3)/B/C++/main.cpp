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

int minusOne(int x){
    return x ? x-1: 2;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n,x;
    cin >> t; 
    while(t--){
        cin >> n ; 
        vi bucket(3);
        int target = n / 3 ; 
        for(int i = 0 ; i < n ; i ++){
            cin >> x;
            bucket[x%3]++;
        }
        int ans = 0 ; 
        for(int i = 0 ; i < 3 ; i ++){
            if(bucket[i]<target){
                int objective = target - bucket[i];
                for(int j = minusOne(i) , it = 1 ; bucket[i]!=target ; j = minusOne(j), it++ ){
                    int dif = min(objective,bucket[j]-target);
                    if(dif>0)
                        bucket[i]+=dif,ans += dif * it,bucket[j]-=dif;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}