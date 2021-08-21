#include<bits/stdc++.h>

using namespace std;

map<char,char> changeTo = {
    make_pair('3','e'),
    make_pair('0','o'),
    make_pair('1','i'),
    make_pair('7','t'),
    make_pair('4','a'),
    make_pair('5','s')
};

void change(string & s){
    for(size_t i = 0 ; i < s.size() ; i ++){
        auto it = changeTo.find(s[i]);
        if(it!=changeTo.end())
            s[i]=it->second;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s,b;
    cin >> s >> b;
    change(s);
    int bSize = b.size();
    string concat = b+"#"+s;
    int concatSize = concat.size();
    vector<int> p(concatSize);
    for(int i = 1 ; i < concatSize ; i ++){
        int x = p[i-1];
        for(;x&&concat[x]!=concat[i];x=p[x-1]);
        if(concat[x]==concat[i])
            x++;
        p[i]=x;
    }
    bool banned = false;
    for(int i = bSize+1;i<concatSize;i++)
        if(p[i]==bSize){
            banned=true;
            break;
        }
    cout << (banned?"YES":"NO") << "\n";
    return 0;
}