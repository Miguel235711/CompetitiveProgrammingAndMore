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

int f(int x){
    return x -  (x >= 500 ? 100 : 0) ;
}

int arr[3];

int search(int i, int order,int ans){
    if(i==3){
        ans += f(order);
        return ans;
    }   
    return min(search(i+1,order+arr[i],ans), search(i+1,arr[i],ans+f(order)));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int minAns = INT_MAX;
    for(int i = 0 ; i < 3 ; i ++)
        cin >> arr[i];
    do{
        minAns = min(search(0,0,0),minAns);
    }while(next_permutation(arr,arr+3));
    cout << minAns << "\n";
    /*sort(arr,arr+3);
    int ans = f(arr[0])+f(arr[1])+f(arr[2]);
    min(ans,f(arr[0]+arr[1]))*/
    return 0;
}