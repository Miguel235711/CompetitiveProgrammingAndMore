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
    int t,n,xi;
    cin >> t;
    while(t--){
        cin >> n ; 
        vi a[2];
        for(int i = 0 ; i < n ; i ++)
            cin >> xi, a[xi&1].pb(xi);
        for(int i = 0 ; i < 2 ; i ++)
            sort(a[i].begin(),a[i].end()),reverse(a[i].begin(),a[i].end());
        v64 is(2),score(2);
        for(int i = 0 ; i < n ; i ++){
            int who = i&1,otherWho = !who;
            if(is[who] == a[who].size() || (is[otherWho] < a[otherWho].size()&&a[otherWho][is[otherWho]]>a[who][is[who]]))
                is[otherWho]++;
            else
                score[who]+=a[who][is[who]++];
        }
        //cout << score[0] << " " << score[1] << "\n";
        cout << (score[0] > score[1] ? "Alice" : (score[1] > score[0] ? "Bob" : "Tie")) << "\n";
    }
    return 0;
}