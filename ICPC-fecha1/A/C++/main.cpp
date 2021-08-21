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

struct es{
    int maxi,firstMax,countMax;
}arr[200008]; // arr[i]
int N,Q;
map<pair<int,int>,int> counts;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> Q ;
    char com;
    int i,j,bestI=1,bestJ=1,bestGAns=-1,bestCountMax=0;
    for(int i = 0 ; i < N ; i ++) arr[i].maxi=-1,arr[i].firstMax=-1;
    while(Q--){
        cin >> com;
        if(com=='R'){
            //register ,tricky!!!
            cin >> i >> j;
            counts[mp(i,j)]++;
            auto inter = counts[mp(i,j)];
            if(arr[i].maxi<inter)
                arr[i].maxi=inter,arr[i].firstMax=j,arr[i].countMax=1;
            else if(arr[i].maxi==inter)
                arr[i].countMax++;
            if(inter>bestGAns){
                bestGAns = inter,bestI=i,bestJ=j,bestCountMax=1;
            }else if(inter==bestGAns){
                bestCountMax++;
            }
        }else if(com=='Q'){
            cin >> i ;  
            ///query of best j for i
            auto sI = arr[i];
            cout << (sI.countMax == 0 ? "No info" :  (sI.countMax == 1 ? to_string(arr[i].firstMax) : "Multiple")) << "\n";
        }else if(com=='B'){
            if(bestCountMax>1)
                cout << "Multiple\n";
            else
                cout << bestI << " " << bestJ << "\n";
        }
    } 
    return 0;
}