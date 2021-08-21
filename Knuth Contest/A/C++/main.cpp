#include<bits/stdc++.h>

using namespace std;

map<char,char>trans={
    make_pair('O','0'),
    make_pair('I','1'),
    make_pair('Z','2'),
    make_pair('E','3'),
    make_pair('A','4'),
    make_pair('S','5'),
    make_pair('G','6'),
    make_pair('T','7'),
    make_pair('B','8')
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;
    for(char c:s){
        auto it = trans.find(toupper(c));
        if(it==trans.end())
            cout << c;
        else
            cout << it->second;
    }
    cout << "\n";
    return 0;
}