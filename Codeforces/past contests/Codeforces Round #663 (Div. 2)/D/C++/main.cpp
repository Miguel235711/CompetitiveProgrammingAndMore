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
#define lim 1000008

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

int arr[4][1000008];
int memo[1000008][8];
int n , m, limP ; 

int getCost(int a,int b){
    int cost = 0 ;
    for(int i = n ; i > 0 ; i--)
        cost+=((a>>(n-i))&1)!=((b>>(n-i))&1);
    return cost;
}

int f(int j,int vis){
    if(j==m)
        return 0;
    if(memo[j][vis]!=-1)
        return memo[j][vis];
    int orig = 0;
    for(int i = 0 ; i < n ; i ++){
        orig<<=1;
        orig+=arr[i][j];
    }
    int ans = n*m;
    for(int v = 0 ; v < limP; v++){
        int l = vis&1 , r = v&1 ;
        int count = l+r;
        for(int i = n - 1 ; i > 0 ; i --){
            int add = ((vis>>(n-i))&1)+((v>>(n-i))&1);
            if((count+add)%2==0){
                count=-1;
                break;
            }
            count = add; 
        }
        if(count!=-1)
            //try possibility
            ans = min(f(j+1,v)+getCost(orig,v),ans);
    }
    return memo[j][vis]=ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m ; 
    if(n>=4)
        cout << -1 << "\n";
    else if(n==1){
        cout << 0 << "\n";
    }else{
        memset(memo,-1,sizeof(memo));
        ///n <=m
        int visI = 0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m;j++){
                char x ;
                cin >> x;
                arr[i][j]=x-'0';
                if(j==0){
                    visI<<=1;
                    visI+=arr[i][j];
                }
            }
        }
        limP = 1 << n;
        int ans = INT_MAX;
        for(int v = 0 ; v < limP ; v ++){
            int cost = getCost(visI,v);
            ans=min(f(1,v)+cost,ans);
        }
        cout << ans << "\n";
    }
    
    return 0;
}