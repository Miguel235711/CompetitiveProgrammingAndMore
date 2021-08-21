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

typedef vector<vector<string> > vvs;

struct containerS{
    int weightR,index;
    stack<int> * packages;
    bool operator <(containerS other)const{
        return packages->size() > other.packages->size() || (packages->size()==other.packages->size()&&weightR<other.weightR) || 
        (packages->size()==other.packages->size()&&weightR==other.weightR&&index>other.index);
    }
    containerS(int weightR,int index,stack<int> * packages):weightR(weightR),index(index),packages(packages){}
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int c,p,wi;
    for(int cs=0;cin >> c;cs++){
        int cargoW = 0 , unusedW = 0 , unloadedW = 0 ;
        if(cs)
            cout << "\n";
        priority_queue<containerS> containers;
        for(int i = 0 ; i < c ; i ++){
            cin >> wi;
            containers.push(containerS(wi,i,new stack<int>()));  
            unusedW+=wi; 
        }
        cin >> p;
        bool process=true;
        size_t maximumStackSize=0;
        while(p--){
            cin >> wi;
            unloadedW+=wi;
            if(process){
                auto cont = containers.top();
                if(cont.weightR<wi)
                    process=false;
                else{
                    //occupy with package weight
                    cargoW+=wi;
                    unusedW-=wi;
                    unloadedW-=wi;
                    cont.weightR-=wi;
                    //add in stack
                    cont.packages->push(wi);
                    MAX(maximumStackSize,cont.packages->size());
                    //return to priority queue
                    containers.pop();
                    containers.push(cont);
                }
            }
        }
        vector<stack<int> *> stRs(c);
        while(!containers.empty()){
            stRs[containers.top().index]=containers.top().packages;
            containers.pop();
        }
        for(size_t sz = 0 ; sz < maximumStackSize ; sz++){
            for(size_t i = 0 ; i < stRs.size() ; i++){
                string ans = ":";
                if(stRs[i]->size()+sz==maximumStackSize){
                    ans = to_string(stRs[i]->top());
                    stRs[i]->pop();
                }
                cout << (i?" ":"") << ans;
            }
            cout << "\n";
        }
        cout << string(c*2-1,'=')<<"\n";
        for(int i = 1; i <= c ; i ++)
            cout << (i!=1?" ":"") << i ;
        cout << "\n\ncargo weight: " <<  cargoW << "\nunused weight: " << unusedW << "\nunloaded weight: " << unloadedW << "\n"; 
    }
    return 0;
}