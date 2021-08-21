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

string s;
int which[12];

//use prime determination with sieve

void f(size_t i){
    if(i == s.size()){
        ///test
        vvi numbers(3);
        for(size_t k = 0 ; k < s.size() ; k ++){
            //cout << "k\n";
            numbers[which[k]].push_back(s[k]-'0');
        }
        for(int j = 0 ; j < 3 ; j ++)
            sort(numbers[j].begin(),numbers[j].end());
        /*for(int j = 0 ; j < numbers[0].size(); j++)
            cout << "a: " << numbers[0][j] << " ";*/
        while(PERMUTE(numbers[0].begin(),numbers[0].end())){
            while(PERMUTE(numbers[1].begin(),numbers[1].end())){
                while(PERMUTE(numbers[2].begin(),numbers[2].end())){
                    cout << numbers[0][0] << "\n";
                }
            }
        }
        return ; 
    }
    for(int j = 0 ; j < 3 ; j ++){
        which[i]=j;
        f(i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> s ;
    f(0);
    return 0;
}