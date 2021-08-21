#include<bits/stdc++.h>
#define inf 200008

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

int t,n,F,La;
string s;

int cost(char newC,int pos){
    return newC!=s[pos];
}

int memo[200008][2][2];

int f(int pos,bool isBA,bool isBBABB){
    if(pos+2==n){
        //especial
        if((F==0&&La==0)||(F==1&&La==0&&!isBA))
            //right
            if(isBA&&isBBABB)
                return inf;
            else 
                return cost('R',pos);
        else if(F==1&&La==1)
            //left
            if(!isBA&&!isBBABB)
                return inf;
            else
                return cost('L',pos);
        else if(F==1&&La==0)
            return 0;
        else
            return isBA ? cost('L',pos) : (isBBABB ? 0: cost('R',pos));
    } 
    if(memo[pos][isBA][isBBABB]!=-1)
        return memo[pos][isBA][isBBABB];
    int ans = INT_MAX;
    if(isBA){
        MIN(ans,f(pos+1,false,isBA)+cost('L',pos));
        if(!isBBABB)
            MIN(ans,f(pos+1,true,isBA)+cost('R',pos));
    }else{
        if(isBBABB)
            MIN(ans,f(pos+1,false,isBA)+cost('L',pos));
        MIN(ans,f(pos+1,true,isBA)+cost('R',pos));
    }
    return memo[pos][isBA][isBBABB]=ans;
}

char iToC(int x){
    return x==0?'L':'R';
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    while(t--){
        cin >> n; 
        cin >> s;
        int ans = INT_MAX;
        for(F = 0 ; F < 2 ; F ++){
            for(La = 0 ; La < 2 ; La++){
                bool isBA=false,isBBABB=false;
                if(F==1)
                    isBA = true;
                if(La==1)
                    isBBABB=true;
                memset(memo,-1,sizeof(memo));
                MIN(ans,
                f(1,isBA,isBBABB)+cost(iToC(F),0)+cost(iToC(La),n-1)
                );
            }
        }
        cout << ans << "\n";
    }
    return 0;
}