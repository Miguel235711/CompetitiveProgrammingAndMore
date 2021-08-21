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

bool matches(string a, string m){
    return a=="*" || a==m;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int M,I;
    for(int cs=1;cin >> M;cs++){
        cout << "Scenario # " << cs << "\n";
        map<string,vvs> MTAs;
        for(int i = 0 ; i < M ; i ++){
            string MTA;
            cin >> MTA >> I;
            vvs adj(I,vs(5));
            for(int j = 0 ; j < I ; j ++){
                for(int k = 0 ; k < 5 ; k ++)
                    cin >> adj[j][k];
            }
            MTAs[MTA]=adj;
        }
        int n;
        cin >> n ; 
        for(int m = 1 ; m <= n ; m ++){
            cout << m << " -- ";
            vs message(5);
            for(int i = 0 ; i < 5 ; i ++){
                cin >> message[i];
            }
            set<string> visitedMTAs;
            visitedMTAs.insert(message[0]);
            for(string MTA = message[0] ; ; ){
                bool finish = false,routed=false;
                for(vs entry:MTAs[MTA]){
                    bool match=true;
                    for(int i = 1 ; i < 5 ; i ++){
                        if(!matches(entry[i],message[i])){
                            match=false;
                            break;
                        }
                    }
                    if(match){
                        if(entry[0]==MTA)
                            cout << "delivered to " << MTA,finish=true;
                        else if(visitedMTAs.find(entry[0])!=visitedMTAs.end())
                            cout << "circular routing detected by " << entry[0],finish=true;
                        else{
                            MTA = entry[0];
                            visitedMTAs.insert(MTA);
                            routed=true;
                        }
                        break;
                    }
                }
                if(finish){
                    break;
                }
                if(!routed){
                    cout << "unable to route at " << MTA;
                    break;
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}