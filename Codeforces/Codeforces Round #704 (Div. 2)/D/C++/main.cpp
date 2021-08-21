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

bool valid=true;
int a,b,k,posY;

vi generateY(){
    int sz = a+b;
    vi y(a+b);
    y[sz-1]=1;
    int tempB =  b-1;
    for(int i = 0 ; i < sz && tempB-- ; i ++)
        y[i]=1,posY =i; 
    return y;
}
vi generateZ(int sz,int k){
    vi z(sz);
    for(int i = max(posY,k-1) ; k-- ; i --)
        z[i]=1;  
    return z;      
}

void printV(vi & v){
    for(int i = v.size()-1 ; i > -1 ; i --)
        cout << v[i] ;
}

vi sumB(vi & v1, vi & v2){
    int carry = 0 ; 
    int ones = 0 ; 
    vi ans(v1.size());
    for(size_t i = 0 ; i < v1.size();i++){
        ans[i] = v1[i]+v2[i]+carry;
        if(ans[i]>1)
            ans[i]-=2, carry = 1;
        else
            carry = 0 ; 
        if(ans[i])
            ones ++;
    }
    valid = ones==b && carry == 0 ;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b >> k ;
    vi y = generateY();
    auto z = generateZ(a+b,k),x = sumB(y,z);
    if(valid){
        cout << "Yes\n";
        printV(x),cout << "\n";
        printV(y);
    }else
        cout << "No";
    cout << "\n";
    return 0;
}