#include<bits/stdc++.h>

using namespace std ; 

std::string::size_type sz;

string s ; 

map<int,int64_t >visited ; 

int64_t f(int x){
    if(!x){
        return 0 ; 
    }
    if(x/2+x/3+x/4<x){
        return x;
    }
    auto it = visited.find(x);
    if(it!=visited.end()){
        return it->second;
    }
    int64_t ans  = f(x/2) + f(x/3) + f(x/4);
    visited.insert(make_pair(x,ans));
    return ans ; 
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(getline(cin,s)){
        cout << f(stoi(s,&sz)) << "\n";
    }
    return 0;
}