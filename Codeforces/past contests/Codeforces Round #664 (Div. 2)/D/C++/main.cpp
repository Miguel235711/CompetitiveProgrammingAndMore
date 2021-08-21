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
    int n , d , m ; 
    cin >> n >> d >> m;
    vi arr(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    /*for(int x:arr){
        cout << x << " ";
    }
    cout << "\n";*/
    i64 acum = 0,firstGreater=0; 
    for(int i = 0 ; i < n ; i ++ ){
        if(arr[i]>m){
            firstGreater=i;
            break;
        }
        acum += arr[i];
    }
    //cout << "initialacum: " << acum << "\n";
    if(firstGreater<=n-1)
        acum+=arr[n-1];
    i64 maxAns = acum;
    int l = -1 ;
    for(int i = n - 2 ; i>l+d && i >= firstGreater ; i --){
        int newL =l + d;
        if(newL>=firstGreater)
            break;
        for(int j = l + 1 ; j <= newL; j ++){
            //cout << j << " " ; 
            acum-=arr[j];
        }
        //cout << "acum after removing: " << acum << "\n";
        acum+=arr[i];
        //cout << "acum: " << acum << "\n";
        maxAns=max(maxAns,acum);
        l=newL;
    }
    cout << maxAns << "\n";
    return 0;
}