#include<bits/stdc++.h>

using namespace std;

map<char,float> durations = {
    make_pair('W',1.0),
    make_pair('H',0.5),
    make_pair('Q',0.25),
    make_pair('E',0.125),
    make_pair('S',0.0625),
    make_pair('T',0.03125),
    make_pair('X',0.015625)
};
bool isRight(string s){
    float sum = 0 ; 
    for(char c:s){
        sum+=durations[c];
    }
    return sum==1;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    while(cin>>s&&s[0]!='*'){
        int ans=0;
        string current="";
        for(size_t i = 1 ; i < s.length() ; i ++){
            if(s[i]=='/'){
                ans+=isRight(current);
                current="";
            }else
                current.push_back(s[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}