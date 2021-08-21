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

string toString(int x){
    //return 3 digit number
    auto cS = to_string(x);
    return string(3-cS.size(),'0')+cS;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    string x;
    cin.ignore();
    getline(cin,x);
    for(int cs=0;cs<t;cs++){
        if(cs)
            cout << "\n";
        vs ram(1000);
        vi registers(10);
        int lim=0;
        while(getline(cin,x)&&!x.empty())
            ram[lim++]=x;
        int ans=1;
        for(int i=0;;i++){
            int d = ram[i][1]-'0' , n = ram[i][2]-'0'; 
            if(ram[i][0]=='1')
                break;
            else if(ram[i][0]=='2')
                registers[d]=n;
            else if(ram[i][0]=='3')
                registers[d]+=n;
            else if(ram[i][0]=='4')
                registers[d]*=n;
            else if(ram[i][0]=='5')
                registers[d]=registers[n];
            else if(ram[i][0]=='6')
                registers[d]+=registers[n];
            else if(ram[i][0]=='7')
                registers[d]*=registers[n];
            else if(ram[i][0]=='8')
                registers[d]=stoi(ram[registers[n]]);
            else if(ram[i][0]=='9')
                ram[registers[n]]=toString(registers[d]);
            else if(registers[n]!=0){
                //goto location in registers[d]
                i = registers[d]-1;
            }
            registers[d]%=1000;
            //cout << registers[1] << "\n";
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}