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

int t,n,xi; 

vii numberAp; // repetitios,number

bool possible(int packetSize){
    int partitions = n / packetSize + (n%packetSize!=0?1:0);
    vector<set<int> > packetsB(partitions);
    int p=0,lastSz=n%packetSize==0?packetSize:n%packetSize;
    for(auto nAp : numberAp){
        for(int rep = 0 ; rep < nAp.first; rep++){
            //cout << "p: " << p << "\n"; 
            if(packetsB[p].find(nAp.second)==packetsB[p].end()){
                packetsB[p].insert(nAp.second);   
                p=(p+1)%partitions;
                if(p+1==partitions&&packetsB[p].size()==lastSz)
                   p=0;
            }
            else
                return false;
        }
    }
    //check sizes
    int lim = packetsB.size()-1;
    for(int i = 0 ; i < lim;i++)
        if(packetsB[i].size()!=packetSize)
            return false;
    return true;
}
int binSearch(){
    int l = 0, r = n-1;
    while(l+1<r){
        int mid = (l+r)/2;
        if(possible(mid+1))
            l = mid;
        else
            r = mid - 1 ; 
    }
    if(possible(r+1))
        return r;
    return l;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ;
    while(t--){
        numberAp.clear();
        map<int,int> aparitions;
        cin >> n;
        for(int i = 0 ; i < n ; i ++){
            cin >> xi;
            aparitions[xi]++;
        }
        for(auto it = aparitions.begin() ; it!=aparitions.end() ; it++ )
            numberAp.push_back(make_pair(it->second,it->first));
        sort(numberAp.begin(),numberAp.end(),greater<pair<int,int> >());
        cout << binSearch() << "\n";
    }
    return 0;
}