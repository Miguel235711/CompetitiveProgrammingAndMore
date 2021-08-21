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
 
int t,n;
 
pair<int,int> points[1008],points2[1008];
 
i64 cost(int x,int y){
    i64 ans = 0 ; 
    for(int i = 0 ; i < n ; i ++)
        ans += abs(points[i].fi-x) + abs(points[i].se-y);
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin  >> t ; 
    while(t--){
        i64 minDist = LLONG_MAX,yMid=0,xMid=0;
        set<pair<int,int> > ans; 
        cin >> n ; 
        for(int i = 0 ; i < n ; i ++){
            cin >> points[i].first >> points[i].second,yMid +=points[i].se,xMid+=points[i].fi;
            points2[i].first = points[i].second;
            points2[i].second = points[i].first;
        }
        yMid/=n,xMid/=n;
        ///for x
        sort(points,points+n);
        //cout << "cost(1,2): " << cost(1,2) << " cost(2,2): " << cost(2,2) << "\n";
        for(int i = 0 ; i < n ; i ++){
            if(!i||points[i].fi!=points[i-1].fi){
                //cout << "x: " << points[i].fi << " y: " << yMid << "\n";
                i64 a = cost(points[i].fi,yMid), b = cost(points[i].fi,yMid+1);
                auto minI = min(a,b);
                if(minI < minDist)
                    minDist = minI, ans.clear();
                if(a==minDist){
                    //cout << "what the heck x: " << points[i].fi << " y: " << yMid << "minDist: " << cost(points[i].fi,yMid) << "\n";
                    ans.insert(mp(points[i].fi,yMid));
                }
                if(b==minDist)
                    ans.insert(mp(points[i].fi,yMid+1));
            }
        }
        //cout << "minDist: " << minDist << "\n";
        /*for(auto it = ans.begin(); it!=ans.end() ; it++){
            cout << it->first << " " << it->second << " withcost:  " << cost(it->first,it->second) << "\n";
        }*/
        //cout << ans.size() << "\n";
        sort(points2,points2+n);
        //for y
        for(int i = 0 ; i < n ; i ++){
            if(!i||points2[i].fi!=points2[i-1].fi){
                i64 a = cost(xMid,points2[i].fi), b = cost(xMid+1,points2[i].fi);
                if(a<minDist)
                    minDist = a, ans.clear();
                if(a==minDist)
                    ans.insert(mp(xMid,points2[i].fi));
                if(b<minDist)
                    minDist = b, ans.clear();
                if(b==minDist)
                    ans.insert(mp(xMid+1,points2[i].fi));
            }
        }
        cout << ans.size() << "\n";
    }
    return 0;
}