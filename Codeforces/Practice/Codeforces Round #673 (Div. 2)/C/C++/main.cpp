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
    int t , n , x ;
    cin >> t;
    while(t --){
        cin >> n;
        vi posV(n+1) /*ai index*/ , maxD(n+1); // ai index
        vvi aiOfMaxD(n+1);
        set<int> xs;
        for(int i = 1 ; i <= n ; i ++){
            cin >> x;
            xs.insert(x);
            MAX(maxD[x],i-posV[x]-1);
            posV[x]=i;
        }
        for(const auto & it : xs){
            MAX(maxD[it],n-posV[it]);
            aiOfMaxD[maxD[it]].push_back(it);
        }
        stack<int> st;
        for(int i = n ; i > 0 ; i --){
            for(const auto & it : aiOfMaxD[i])
                xs.erase(it);
            st.push(xs.empty()?-1:(*xs.begin()));
        }
        while(!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
        cout << "\n";
    }
    return 0;
}