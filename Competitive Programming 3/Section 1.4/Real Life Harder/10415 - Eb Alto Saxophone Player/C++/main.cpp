#include<bits/stdc++.h>

using namespace std;

typedef vector<pair<int,int> > vP;


map<char,vP > ranges={
    make_pair('c',vP{make_pair(2,4),make_pair(7,10)}),
    make_pair('d',vP{make_pair(2,4),make_pair(7,9)}),
    make_pair('e',vP{make_pair(2,4),make_pair(7,8)}),
    make_pair('f',vP{make_pair(2,4),make_pair(7,7)}),
    make_pair('g',vP{make_pair(2,4)}),
    make_pair('a',vP{make_pair(2,3)}),
    make_pair('b',vP{make_pair(2,2)}),
    make_pair('C',vP{make_pair(3,3)}),
    make_pair('D',vP{make_pair(1,4),make_pair(7,9)}),
    make_pair('E',vP{make_pair(1,4),make_pair(7,8)}),
    make_pair('F',vP{make_pair(1,4),make_pair(7,7)}),
    make_pair('G',vP{make_pair(1,4)}),
    make_pair('A',vP{make_pair(1,3)}),
    make_pair('B',vP{make_pair(1,2)})
};
bool notContained(int i, char c){
    if (c=='\0')
        return true;
    for(auto range : ranges[c])
        if (range.first <= i && i <= range.second)
            return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        char last ='\0';
        vector<int>output(10);
        string line;
        getline(cin,line);
        for (auto c:line){
            for(auto range: ranges[c])
                for(int i = range.first ; i <= range.second ; i ++)
                    if (notContained(i,last))
                        output[i-1]++;
            last = c;
        }
        for(size_t i = 0 ; i < output.size() ; i ++)
            cout << output[i] << (i+1!=output.size()?" ":"");
        cout << "\n";
    }
    return 0;
}