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
#define MODP 1000000007
#define prime 29

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

int n;
vvi hashes;
vi pri;
vs strs;

int toV(char x){
    return x-'a'+1;
}

int mod(i64 x){
    return x % MOD;
}

int modNeg(i64 x){
    return mod(x + MOD);
}

int getHash(int i,int ending,int E){
    // i = {2,3} , ending = 1 , E = 0  
    //cout << "ending: " << ending << " strs[i].size(): " << strs[i].size() << "\n";
    if(ending==-1) // empty
        return 0;
    if(E>ending||E==-1)
        return hashes[i][ending];
    ///0<=E<=ending
    int distEToEnding = ending-E;
    int leftSub = E ? mod((i64)hashes[i][E-1]*pri[distEToEnding+1]):0;
    /*if((i==2 || i==3) && ending == 1 && E == 0)
        cout << "i: " << i << " leftSub: " << leftSub << "\n";*/
    /*if(i==3&&ending==1&&E==1)
        cout << "should be 0:" << mod((i64)modNeg(modNeg(hashes[i][ending]-mod((i64)toV(strs[i][E])*pri[distEToEnding])) - leftSub) * prime) << "\n",
        cout << "leftSub: " << leftSub << "\n";*/
    return
    mod(
        mod((i64)modNeg(modNeg(hashes[i][ending]-mod((i64)toV(strs[i][E])*pri[distEToEnding])) - leftSub) * prime) 
        + leftSub+toV(strs[i][ending+1])
    );
}

bool equal(int i,int ending,int lE,int iE){
    return getHash(i,ending,iE) == getHash(i-1,ending,lE);
}

///index from 0

bool valid(int i,int lE,int iE){ ///if erased are  -1, dont erase
    ///i, lastErased, iErased
    ///find first different 
    if(!i)
        return true;
    int sIH = hashes[i].size()-(iE!=-1?1:0) , sLH = hashes[i-1].size()-(lE!=-1?1:0);
    int l = 0 , r = min(sIH,sLH)-1;
    while(l+1<r){
        int mid = (l+r)/2;
        if(equal(i,mid,lE,iE))
            l = mid + 1;
        else
            r = mid ; 
    }
    int v = !equal(i,l,lE,iE) ? l : (!equal(i,r,lE,iE)?r:-1);
    /*if(i==1&&lE==1 && iE==0)
        cout << "l: " << l << " r: " << r << " v: " << v << "\n";*/
    /*if(i==3 && lE == 0 && iE == 0 )
        cout << "l: " << l << " r: " << r << " v: " << v << "\n";*/
    return v==-1 ? sIH >= sLH : strs[i][v+(v>=iE)]>strs[i-1][v+(v>=lE)];
}

int memo[1008][20008];

int f(int i, int lE){
    if(i==n)
        return 1;
    if(memo[i][lE+1]!=-1)
        return memo[i][lE+1];
    int ans = 0, szHash = hashes[i].size();
    for(int iE = -1 ; iE < szHash; iE ++)
        if(valid(i,lE,iE))
            ans=(ans+f(i+1,iE))%MODP;
    return memo[i][lE+1] = ans; 
}

void saveHash(int i){
    hashes[i].resize(strs[i].size());
    hashes[i][0]=toV(strs[i][0]);
    for(size_t j = 1 ; j < strs[i].size() ; j ++)
        hashes[i][j]=mod((i64)hashes[i][j-1]*prime + toV(strs[i][j]));
}

void initHashPrimes(int maxPri){
    pri.resize(maxPri+1);
    pri[0]=1;
    for(int i = 1 ; i <= maxPri; i ++)
        pri[i]=mod((i64)pri[i-1]*prime);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    hashes.resize(n);
    strs.resize(n);
    int maxPri = 0 ;
    memset(memo,-1,sizeof(memo));
    for(int i = 0 ; i < n ; i++)
        cin >> strs[i] , saveHash(i), maxPri = max(maxPri,(int)strs[i].size());
    initHashPrimes(maxPri);
    cout << f(0,-1) << "\n";
    /*if(n==4)
        cout << "valid: " << valid(1,1,0) << " equal:  " << equal(1,0,1,0) << "equal: " << equal(1,1,1,0) << "\n";*/
    /*if(n==4)
        cout << "valid: " << valid(3,0,0) << "\n" , cout << "equal: " << equal(3,1,0,0) << "\n",
        cout << getHash(2,1,0) << " " << getHash(3,1,0) << "\n"; 
    if(n==4)
        cout << "valid: " << valid(1,0,0) << " valid: " << valid(1,2,0) << "\n";
    if(n==4)
        cout << "valid: " << valid(3,0,1)  << " valid: " << valid(3,0,0) << "\n",
        cout << "equal: " << equal(3,1,0,1) << "hashPrev " << getHash(3,1,0) << " hashCur " << getHash(3,1,1) << "\n"; */
    return 0;
}