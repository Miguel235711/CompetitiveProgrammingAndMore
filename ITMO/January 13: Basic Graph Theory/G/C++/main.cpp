#include <bits/stdc++.h>

using namespace std;

int n;
map<string,string> parent;
map<string,int> depth;

int f(string current){
    int count = 0 ;
    for(string a = current;;a = parent[a]){
        //cout << "a: " << a << "\n";
        if(depth[a]!=0){
            count += depth[a];
            break;
        }
        count ++;
    }
    return depth[current] = count;
}

void tolower(string & x){
    for(size_t i = 0 ; i < x.size(); i ++)
        x[i] = tolower(x[i]);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    string a,b,_;
    while(n--){
        cin >> a >> _ >> b;
        tolower(a),tolower(b);
        //cout << "a: " << a << " b: " << b << "\n";
        parent[a] = b;
    }
    int ans = 0 ;
    depth["polycarp"]=1;
    for(auto it = parent.begin(); it!= parent.end() ; it++){
        auto a = it->first;
        if(depth[a]==0)
            ans = max(f(a),ans);
    }
    cout << ans << "\n";
    return 0;
}