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

int t,n,n2;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    while(t--){
        cin >> n ; 
        n2 = n << 1 ; 
        vi a(n2);
        for(int i = 0 ; i < n2 ; i ++)
            cin >> a[i];
        sort(a.begin(),a.end());
        int lim = n2-1;
        vector<pair<int,int> > ans;
        int initX = 0;
        for(int r = 0 ; r < lim ; r ++){
            multiset<int> nums;
            for(int i = 0 ; i < n2 ; i ++)
                nums.insert(a[i]);
            nums.erase(nums.find(a[r])),nums.erase(nums.find(a[n2-1]));
            ans.push_back({a[n2-1],a[r]});
            int x = a[n2-1];
            if(!nums.empty()){
                auto it = nums.end();
                it--;
                while(!nums.empty()){
                    auto cpIt = it;
                    it--;
                    auto vToFind = x - *cpIt;
                    x = *cpIt;
                    nums.erase(cpIt);
                    auto fV = nums.find(vToFind);
                    if(fV==nums.end()){
                        ans.clear();
                        break;
                    }
                    ans.push_back({x,vToFind});
                    if(it==fV&&it!=nums.begin())
                        it--;
                    nums.erase(fV);
                }
            }
            if(!ans.empty()){
                initX = a[n2-1]+a[r];
                break;
            }
        }
        if(ans.empty())
            cout << "NO\n";
        else{
            cout << "YES\n"<<initX<<"\n";
            for(auto e:ans)
                cout << e.fi << " " << e.se << "\n";
        }
    }
    return 0;
}