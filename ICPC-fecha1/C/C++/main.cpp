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
#define lim 200008

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

int bestAns[lim];
int parent [lim],sz[lim];
unordered_map<string,int> toIndex;
string toString[lim];
int countIndex;

int findU(int a){
    while(parent[a]!=a){
        a = parent[a] = parent[parent[a]];
    }
    return a;
}

int calcAnsU(int a,int b){
    string aS = toString[bestAns[a]] , bS = toString[bestAns[b]];
    //cout << "a: " << a << "b: " << b << " a<b? " << (aS.size()<bS.size() ? a : (aS.size()==bS.size() ? (aS < bS ? a : b) : b))<<"\n";
    return aS.size()<bS.size() ? bestAns[a] : (aS.size()==bS.size() ? (aS < bS ? bestAns[a] : bestAns[b]) : bestAns[b]);
}

void unionU(int a,int b){
    int rootA = findU(a), rootB = findU(b);
    ///make condition satisfy rootA.size > rootB.size
    //cout << "rootA: " << rootA << " rootB: " << rootB << " a: " << a << " b: " << b << " sz[rootA]: "<< sz[rootA] << " sz[rootB]: " << sz[rootB] << "\n"; 
    if(rootA!=rootB){
        if(sz[rootA]<sz[rootB])
            swap(a,b);
        parent[rootB]=rootA;
        sz[rootA]+=sz[rootB];
        bestAns[rootA]=calcAnsU(rootA,rootB);
    }
}

int addToMapIfDontExists(const string & a){
    auto it = toIndex.find(a);
    if(it==toIndex.end()){
        toIndex[a]=countIndex;
        toString[countIndex]=a;
        parent[countIndex]=countIndex;
        sz[countIndex]=1;
        bestAns[countIndex]=countIndex;
        return countIndex++;
    }
    return it->second;
}

string calcAns(const string & a){
    if(a.empty()) ///helper special case
        return "";
    //cout << "to calculate "<< a << "\n";
    auto it = toIndex.find(a);
    if(it==toIndex.end()) ///when there is no way of chaging it
        return a;
    int root = findU(it->second); 
    return toString[bestAns[root]];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    string a,b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        int indexA = addToMapIfDontExists(a), indexB = addToMapIfDontExists(b);
        //cout << "indexA: " << indexA << " indexB: " << indexB << " -> ";
        //cout << "aS: " << toString[indexA] << " bS: " << toString[indexB] << "\n";
        unionU(indexA,indexB);
    }
    cin.ignore();
    getline(cin,a);
    string current;
    for(char x : a){
        if(x==' '){
            cout << /*"symplified from: " << current << " " <<*/ calcAns(current) << " ";
            current = "";
        }else{
            current.push_back(x);
        }
    }
    /*cout << "indexes:\n";
    cout << "toIndex: " << toIndex["are"] << "parent from  ans: " << parent[toIndex["are"]]<< " " << bestAns[toIndex["are"]] << "\n";
    cout << "toIndex: " << toIndex["r"] << "parent from ans: " << parent[toIndex["r"]] << " " << bestAns[toIndex["r"]] << "\n";
    cout << "toIndex: " << toIndex["ok"] << "parent from  ans: " << parent[toIndex["ok"]]<< " " << bestAns[toIndex["ok"]] << "\n";
    cout << "toIndex: " << toIndex["k"] << "parent from ans: " << parent[toIndex["k"]] << " " << bestAns[toIndex["k"]] << "\n";
    cout << "toIndex: " << toIndex["z"] << "parent from ans: " << parent[toIndex["z"]] << " " << bestAns[toIndex["z"]] << "\n";
    cout << "\n----------\n";*/
    //cout << "lastOne: " << current << " parent: ";
    //cout << bestAns[toIndex[current]] << "\n";
    cout << calcAns(current);
    cout << "\n";
    return 0;
}