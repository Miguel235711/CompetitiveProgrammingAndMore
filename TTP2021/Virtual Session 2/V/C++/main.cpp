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

///operators overloading
void operator+=(pii& a,const pii&b){
    a.fi+=b.fi;
    a.se+=b.se;
}
pii operator+(const pii& a,const pii&b){
    return {a.fi+b.fi,a.se+b.se};
}

void operator-=(pii& a,const pii&b){
    a.fi-=b.fi;
    a.se-=b.se;
}
pii operator-(const pii& a,const pii&b){
    return {a.fi-b.fi,a.se-b.se};
}

i64 worstAns;

i64 cost(p64 x,i64 ai){
    return x.se>worstAns ? LLONG_MAX : x.fi*ai+x.se;
}

double xInt(p64 a,p64 b){
    return ((double)(b.se - a.se))/((double)(a.fi-b.fi)); 
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n ;
    vi a(n),b(n);
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];
    for(int i = 0 ; i < n ; i ++)
        cin >> b[i];
    ///dp with convex hull trick
    deque<p64> q;
    q.pb({b[0],0});
    worstAns = (i64)a[n-1]*b[0];
    i64 ans;
    for(int i = 1 ; i < n ; i ++){
        ///calculate answer
        auto e = q.front();
        q.pop_front();
        for(;!q.empty()&&xInt(e,q.front())<=a[i];q.pop_front()){
            //cout << "xInt: " << xInt(e,q.front()) << "\n";
            e = q.front();
            //cout << "to pop\n";
        }
        q.push_front(e);
        ans = cost(e,a[i]);
        //cout << "chosen: " << e.fi << " " << e.se << " ans: " << ans << "\n";
        ///pop from back while it is mandatory
        if(i+1<n&&ans!=LLONG_MAX){
            auto nw = mp(b[i],ans);
            while(q.size()>1){ 
                auto inter = q.back();
                q.pop_back();
                if(xInt(inter,q.back())<xInt(nw,q.back())){
                    q.push_back(inter);
                    break;
                }
                //cout << "nw: " << nw.fi << " " << nw.se << " q.back(): " << q.back().fi << " " << q.back().se << "\n";
                //cout << "going to oop and xInt: " << xInt(nw,q.back()) << "\n";
            }
            q.push_back(nw);
        }
    }
    cout << ans << "\n";
    return 0;
}