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

const int lim = 100008;


multimap<int,int> indexesSorted;
int bonus[lim],performance[lim];///ans
int n,b;

int getBefore(int i){
    return i>1 ? i - 1 : n;
}
int getNext(int i){
    return i % n + 1 ; 
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> b ; /// use b for the end
    memset(bonus,-1,sizeof(bonus));
    for(int i = 1; i <= n ; i ++){
        cin >> performance[i];
        indexesSorted.insert(make_pair(performance[i],i));
    }
    for(auto it = indexesSorted.begin(); it!=indexesSorted.end(); it++){
        //cout << it->first << " " << it->second << "\n";
        int i = it->second, p = it->first;
        int l = getBefore(i), r = getNext(i);
        int bonusLeft = bonus[l], bonusRight = bonus[r];
        int myP = performance[i], lP = performance[l], rP = performance[r];
        if( i == 2 ) 
            cout << bonusLeft << " " << bonusRight << "baseP: " << p << "\n";
        if(myP>lP&&bonusLeft!=-1)
            bonus[i] = max(bonus[i],bonusLeft+1);
        if(myP>rP&&bonusRight!=-1)
            bonus[i] = max(bonus[i],bonusRight+1);
    }
    for(int i = 1 ; i <= n ; i ++)
        cout << (int64_t) bonus[i] * b << " ";
    cout << "\n";
    return 0;
}