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

#define m 998244353

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

int64_t exp(int64_t base,int64_t power){
    if(!power) return 1 ;
    int64_t x = exp(base,power/2);
    x=(x*x)%m;
    if(power&1) x=(x*base)%m;
    return x ;
}

int64_t division(int64_t a , int64_t b ){
    ///return (a%m)/(b%m)
    return((a%m)*(exp(b,m-2)%m))%m;
}

const int lim = 300002;

i64 factorial[lim];

i64 NInK(int N,int K){
    return N>=K ? division(factorial[N],factorial[K]*factorial[N-K]%m):0;
}
void calcFact(int n){
    factorial[0]=1;
    for(int i = 1 ; i <= n ; i ++)
        factorial[i]=factorial[i-1]*i%m;
}



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k,li,ri;
    cin >> n >> k;
    calcFact(n);
    vi sortedBeg(n),sortedEnd(n);
    for(int i=0 ; i < n ; i ++){
        cin >> li >> ri;
        sortedEnd[i] = ri, sortedBeg[i] = li; 
    }
    SORT(sortedBeg);
    SORT(sortedEnd);
    int pBeg = 0 ; ///until exclusive 
    i64 ans = 0; 
    for(int i = 0 ; i < n ; i ++){
        int already = pBeg;
        //cout << sortedBeg[i] << " " << sortedEnd[i] << "\n";
        while(pBeg < n&&sortedBeg[pBeg] <= sortedEnd[i])
            pBeg++;
        cout << "pBeg: " << pBeg << " k: " << k << " already: " << already << "\n";
        ans += (NInK(pBeg,k) - NInK(already,k)+m)%m;
        ans%=m;
    }
    cout << ans << "\n";
    return 0;
}