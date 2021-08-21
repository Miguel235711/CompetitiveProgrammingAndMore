#include<bits/stdc++.h>

#define mp make_pair 
#define pb push_back 
#define sz size
#define FOR(a, b, c) for ((a) = (b); (a) < (c); ++(a)) 
#define FORN(a, b, c) for ((a) = (b); (a) <= (c); ++(a)) 
#define FORD(a, b, c) for ((a) = (b); (a) >= (c); --(a)) 
#define FORSQ(a, b, c) for ((a) = (b); (a) * (a) <= (c); ++(a)) 
#define REP(i, n) FOR(i, 0, n) 
#define REPN(i, n) FORN(i, 1, n) 
#define MAX(a, b) a = max(a, b) 
#define MIN(a, b) a = min(a, b) 
#define SQR(x) ((x) * (x)) 
#define RESET(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end() 
#define SORT(v) sort(ALL(v)) 
#define PERMUTE next_permutation
#define fi first 
#define se second

#define MOD 1000000009 //1E9+9

using namespace std;

typedef int64_t LL;

typedef pair<LL,LL> pl;
typedef vector<LL> vl;
typedef vector<pl> vpl;
typedef vector <vl> vvl;

typedef double dl;
typedef long double ldl;
typedef pair<string, string> ps;

typedef pair<int,int> pi; 
typedef vector<int> vi;
typedef vector< pi > vii;
typedef vector< vi > vvi;

typedef pair<int,string> pis;

typedef priority_queue<int> pqi;
typedef priority_queue<pi> pqii;

map<char,int> mapCardToInt ={
    mp('A',0),
    mp('T',9),
    mp('J',10),
    mp('Q',11),
    mp('K',12)
};
int cardToInt(char c){
    return '2'<=c && c <= '9' ? c-'1' : mapCardToInt[c];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string cardS;
    while(1){
        stack<pis> stacks[13];
        for(int i=0;i<4;i++)
            for(int j=12;j>-1;j--){
                cin >> cardS;
                if(cardS[0]=='#')
                    return 0;
                stacks[j].push(mp(cardToInt(cardS[0]),cardS));
            }
        for(int j = 0 ; j < 13 ; j++){
            queue<pis> inter;
            for(;!stacks[j].empty();stacks[j].pop())
                inter.push(stacks[j].top());
            for(;!inter.empty();inter.pop()){
                stacks[j].push(inter.front());
            }
        }
        auto card = stacks[12].top();
        stacks[12].pop();
        for(int counter = 1;;counter++){
            if(stacks[card.fi].empty()){
                printf("%02d,%s\n",counter,card.se.c_str());
                break;
            }else{
                int ind = card.fi;
                card = stacks[card.fi].top();
                stacks[ind].pop();
            }
        }
    }
    return 0;
}