#include<bits/stdc++.h>

using namespace std ; 

string s ; 
std::string::size_type sz; 

int64_t memo[5002];

int64_t f(int i){
    if(i==s.size()){
        return 1 ; 
    }
    if(s[i]=='0')  
        return 0 ; 
    if(memo[i]){
       return memo[i]; 
    }
    return memo[i] = (i+1==s.size() ||s[i+1]!='0' ? f(i+1):0) + (i+1 < s.size() && stoi(string({s[i],s[i+1]}),&sz) < 27 ? f(i+2) : 0 );
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> s,s[0]!='0'){ 
        memset(memo,0,sizeof(memo));
        cout << f (0) << "\n";
    }
    return 0;
}