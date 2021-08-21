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

bool bucket[1000];


void initBucket(){
    bucket['.'-'\0']=1;
    bucket['#'-'\0']=1;
    bucket['$'-'\0']=1;
    bucket['%'-'\0']=1;
    bucket['/'-'\0']=1;
    bucket['('-'\0']=1;
    bucket['&'-'\0']=1;
    bucket[')'-'\0']=1;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int t;
    string s;
    cin >> t ; 
    initBucket();
    for(int cs=1 ; cs <= t ; cs++){
        cin >> s;
        int atLeastLower=0, atLeastUpper = 0, atLeastFromSet = 0, atLeast10Chars = s.size()>9?1:0, digitsRule = 1;
        bool atLeastOneDigit = false;
        char last = '\0';
        for(size_t i = 0 ; i < s.size() ; i ++){
            char x = s[i];
            if(islower(x))
                atLeastLower=1;
            if(isupper(x))
                atLeastUpper=1;
            if(bucket[x-'\0'])
                atLeastFromSet=1;
            atLeastOneDigit|=isdigit(x);
            if(isdigit(last)&&isdigit(x)){ ///consecutive  invalidate rule
                digitsRule = 0;
            }
            last = x;
        }
        int sum = atLeastLower+atLeastUpper+atLeastFromSet+atLeast10Chars+(atLeastOneDigit?digitsRule:0);
        cout << "Assertion number #" << cs << ": ";
        if(sum>4){
            cout << "Strong";
        }else if(sum==4){
            cout << "Good";
        }else if(sum==3){
            cout << "Weak";
        }else{
            cout << "Rejected";
        }
        cout << "\n";
    }
    return 0;
}