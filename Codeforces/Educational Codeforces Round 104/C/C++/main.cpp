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
    int t,n;
    cin >> t;
    while(t--){
        cout << "what\n";
        cin >> n ;
        vector<vector<bool> > tieV(n+1,vector<bool>(n+1));
        vector<vector<int> > ans(n+1,vector<int>(n+1));
        int maxV = n*(n-1)/2/n;
        vi countV(n+1);
        if(!(n&1)){
            for(int i = 1 ; i <= n ; i+=2)
                tieV[i][i+1]=true;
        }
        ///make movements
        vector<pair<int,int> > movs;
        int l = 0,r = 0 ;
        for(int i = 1 ; i < n ; i ++){
            for(int j = i+1 ; j <= n ; j ++){
                if(!tieV[i][j]){
                    if(j==n&&i==1)
                        l = movs.size();
                    else if(i == 2 && j == 1)
                        r = movs.size();
                    movs.push_back(make_pair(i,j));
                }
            }
        }
        cout << "n: " << n << " l: " << l << " r: " << r << "\n";
        return 0;
        for(int c = 0 ;l>-1 || r <movs.size();c++){
            int i,j;
            if(l==-1||((c&1)&&r<movs.size())) 
                i = movs[r].first,j=movs[r].second,r++;
            else
                i = movs[l].first, j = movs[l].second,l--;
            int an = 1;
            if(countV[i]==maxV&&countV[j]==maxV)
                an = 0;
            else
                if(countV[i]==maxV)
                    an=-1,countV[j]++;
                else
                    countV[i]++;
            ans[i][j]=an;
        }

        for(int i = 1 ; i < n ; i ++){
            for(int j = i+1 ; j <= n ; j ++){
                if(tieV[i][j])
                    cout << 0;
                else 
                    cout << ans[i][j];
                cout <<" ";
            }
        }
        cout << "\n";
    }
    return 0;
}