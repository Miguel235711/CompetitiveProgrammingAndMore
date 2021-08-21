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

#define MOD 1000000007 //1E9+7

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

/*bool someGreater(int i, int j,const vi & arr,int v){
    for(;i<=j;i++){
        if(arr[i]>v)
            return true;
    }
    return false;
}

bool cyclic(const vi & arr){
    for(int i = 0 ; i < arr.size();i++){
        if(i>1&&arr[i-1]<arr[i]&&someGreater(0,i-2,arr,arr[i]))
            return true;
        if(i<arr.size()-2&&arr[i+1]<arr[i]&&someGreater(i+2,arr.size()-1,arr,arr[i]))
            return true;
    }
    return false;
}*/

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    /*int n, ans=0 ; 
    cin >> n ; 
    vi arr(n);
    for(int i = 0 ; i < n ; i ++)
        arr[i]=i+1;
    do{
        if(cyclic(arr)){
            ans++;
            for(int i = 0 ; i < n ; i ++)
                cout << arr[i] << " ";
            cout << "\n";
        }
    }while (next_permutation(arr.begin(),arr.end()));
    cout << ans << "\n";*/
    i64 n ; 
    cin >> n;
    i64 fact = 1;
    for(i64 i = 2 ; i <= n ; i ++)
        fact=(fact*i)%MOD;
    i64 power2 = 1;
    for(i64 j = 1 ; j < n ; j ++)
        power2=(power2*2)%MOD;
    cout << ((fact-power2)%MOD+MOD)%MOD << "\n";
    return 0;
}