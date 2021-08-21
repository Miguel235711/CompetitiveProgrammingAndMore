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

int gamesWon[2],currentPoints[2],server=1;

string strWin(int who){
    return gamesWon[who]>1 ? "(winnner)" : "";
}
string subStrWin(int who){
    return currentPoints[who]>currentPoints[1-who] ? "*" : "";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;
    for(char x:s){
        if(x!='Q'){
            int who = x=='S' ? server : 1 - server;
            currentPoints[who]++;
            if(currentPoints[who]>=10 || (currentPoints[who]>4 && currentPoints[who]-currentPoints[1-who]>1)){
                gamesWon[who]++;
                memset(currentPoints,0,sizeof(currentPoints));
                server = who;
            }
        }else{
            ///game finished
            if(gamesWon[0]>1 || gamesWon[1]>1){
                //all finished !!!
                cout << gamesWon[0] << " " << strWin(0) << " - " << gamesWon[1] << " " << strWin(1) << "\n";
            }else{
                ///inter
                cout << gamesWon[0] << " (" << currentPoints[0] << subStrWin(0) << ") - " 
                << gamesWon[1] << " (" << currentPoints[1] << subStrWin(1) << ")" << "\n" ;
            }
            //reset points
            
        }
    }
}