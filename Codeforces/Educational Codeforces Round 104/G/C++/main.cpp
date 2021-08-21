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

#define MOD 998244353

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

int memo[400][26][26],n;
int a[26];

int f(int i,int l,int l2){
    if(i==n)
        return 1;
    if(memo[i][l][l2])
        return memo[i][l][l2];
    for(int j = 0 ; j < 26 ; j ++){
        if(i<=1||l2!=j)
            memo[i][l][l2]+= f(i+1,j,l), memo[i][l][l2]%=MOD;
    }
    return memo[i][l][l2];
}

int memo2[400][402][2][2];

int g(int i, int amount ,bool l,bool l2){
    if(i==n)
        return !amount;
    if(memo2[i][amount][l][l2]!=-1)
        return memo2[i][amount][l][l2];
    memo2[i][amount][l][l2] = 0;
    if(i<=1 || l2){
        /// take forbiden with 0 id
        memo2[i][amount][l][l2] += g(i+1,max(amount-1,0),0,l);
        memo2[i][amount][l][l2] %= MOD;
    }
    memo2[i][amount][l][l2] += (int64_t) g(i+1,amount,1,l)*(l2?24:25)%MOD;
    memo2[i][amount][l][l2]%=MOD; 
    return memo2[i][amount][l][l2];
}

int memo3[2][402][402][3][3],maxA;

int h(int i, int amount , int amount2 ,int l,int l2){
    if(i==n)
        return !amount && !amount2;
    if(memo3[i][amount][amount2][l][l2]!=-1)
        return memo3[i][amount][amount2][l][l2];
    memo3[i][amount][amount2][l][l2] = 0;
    if(i<=1 || l2!=0){
        memo3[i][amount][amount2][l][l2] += h(i+1,max(amount-1,0),amount2,0,l);
        memo3[i][amount][amount2][l][l2] %=MOD;
    }
    if(i<=1 || l2!=1){
        memo3[i][amount][amount2][l][l2] += h(i+1,amount,max(amount2-1,0),1,l);
        memo3[i][amount][amount2][l][l2] %=MOD;
    }
    memo3[i][amount][amount2][l][l2] += (int64_t) h(i+1,amount,amount2,2,l)*(l2!=2?24:23)%MOD; 
    memo3[i][amount][amount2][l][l2] %=MOD;
    return memo3[i][amount][amount2][l][l2];
}
void dp(){
    int nAnd1 = n&1;
    for(int l = 0 ; l < 3 ; l ++)
        for(int l2 = 0 ; l2 < 3 ; l2++)
            memo3[nAnd1][0][0][l][l2]=1;
    for(int i = n - 1 ; i > -1 ; i --){
        int iAnd1 = i&1,lastI = (i+1)&1;
        for(int l = 0 ; l < 3 ; l ++){
            for(int l2 = 0 ; l2 < 3 ; l2++){
                for(int amount = 0 ; amount <= maxA ; amount++){
                    for(int amount2 = 0 ; amount2 <= maxA; amount2++){
                        memo3[iAnd1][amount][amount2][l][l2]=0;
                        if(i<=1 || l2!=0){
                            memo3[iAnd1][amount][amount2][l][l2] += memo3[lastI][max(amount-1,0)][amount2][0][l];
                            memo3[iAnd1][amount][amount2][l][l2] %=MOD;
                        }
                        if(i<=1 || l2!=1){
                            memo3[iAnd1][amount][amount2][l][l2] += memo3[lastI][amount][max(amount2-1,0)][1][l];
                            memo3[iAnd1][amount][amount2][l][l2] %=MOD;
                        }
                        memo3[iAnd1][amount][amount2][l][l2] += (int64_t) memo3[lastI][amount][amount2][2][l]*(l2!=2?24:23)%MOD; 
                        memo3[iAnd1][amount][amount2][l][l2] %=MOD;   
                    }
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < 26 ; i ++)
        cin >> a[i],maxA=max(a[i],maxA);
    maxA++;
    //cout << "maxA: " << maxA << "\n";
    int ans = f(0,0,0);
    //cout << ans << "\n";
    //cout << ans << "\n";
    memset(memo2,-1,sizeof(memo2));
    //memset(memo3,0,sizeof(memo3));
    dp();
    for(int i = 0 ; i < 26 ; i ++){
        for(int j = i + 1 ; j < 26; j ++)
            ans = (ans+memo3[0][a[i]+1][a[j]+1][0][0])%MOD;
            //ans = (ans+h(0,a[i]+1,a[j]+1,0,0))%MOD;
        ans-=g(0,a[i]+1,0,0);
        ans = (ans+MOD)%MOD;
    }
    cout << ans << "\n";
    return 0;
}