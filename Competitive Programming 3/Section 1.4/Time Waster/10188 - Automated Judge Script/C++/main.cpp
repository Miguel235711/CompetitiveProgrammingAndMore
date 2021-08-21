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


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    for(int cs=1;cin>>n&&n;cs++){
        vs expectedS;
        string line;
        cin.ignore();
        ///expected
        for(int i = 0 ; i < n ; i ++){
            getline(cin,line);
            expectedS.push_back(line);
        }
        ///given
        cin >> m;
        cin.ignore();
        bool allSame = true, numericCorrespond=true;
        int lim = max(m,n);
        size_t eI = 0 , eJ = 0 ;
        for(int i = 0 ; i < lim ; i++){
            if(i<m)
                getline(cin,line);
            else
                line="";
            if(i>=n)
                expectedS.push_back("");
            allSame&=line==expectedS[i];
            //numericCorrespond&=line.size()==expectedS[i].size();
            for(const auto c: line)
                if(isdigit(c)){
                    while(1){
                        while(eI<expectedS.size()&&eJ>=expectedS[eI].size())
                            eI++,eJ=0;
                        if(eI>=expectedS.size()){
                            numericCorrespond=false;
                            break;
                        }
                        if(isdigit(expectedS[eI][eJ]))
                            break;
                        eJ++;
                    }
                    if(eI<expectedS.size())
                        numericCorrespond&=expectedS[eI][eJ++]==c;
                }
        }
        cout << "Run #" << cs << ": " << (allSame?"Accepted":(numericCorrespond?"Presentation Error":"Wrong Answer")) << "\n";
    }
    return 0;
}