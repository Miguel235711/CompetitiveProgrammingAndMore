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

int t;
string s;

int toInt(char x){
    return x-'A';
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    while(t--){
        cin >> s ;
        vi val(3);
        if(s[0]==s[s.size()-1]){
            cout << "NO\n";
            continue;
        }
        set<int> num({1,2,3});
        int f = toInt(s[0]), l = toInt(s[s.size()-1]);
        val[f]=1,val[l]=-1;
        int withNeg = 0 , withPos = 0 ;
        for(char c : s){
            int v = toInt(c);
            if(val[v])
                withNeg += val[v], withPos += val[v];
            else
                withNeg--,withPos++;
            if(withNeg<0)
                withNeg = 150;
            if(withPos<0)
                withPos = 150;
        }
        cout << (!withNeg || !withPos ? "YES":"NO") << "\n";
    } 
    return 0;
}