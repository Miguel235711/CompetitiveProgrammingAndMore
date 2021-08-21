#include<bits/stdc++.h>
 
using namespace std;

map<char,int> toInd={
    make_pair('R',0),
    make_pair('L',1),
    make_pair('U',2),
    make_pair('D',3)
};
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,x,y;
    string s;
    cin >> t;
    while(t--){
        cin >> x >> y >> s;
        vector<int> v(4);
        for(auto c: s)
            v[toInd[c]]++;
        cout << (((y<0&&-y<=v[3]) || (y>=0&&y <= v[2])) && ((x<0 && -x <= v[1]) || (x>=0 &&x <= v[0]))?"YES":"NO") << "\n"; 
    }
    return 0;
}