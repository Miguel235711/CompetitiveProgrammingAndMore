#include<bits/stdc++.h>

using namespace std;

map<char,char> mapToLeft={
    make_pair('1','`'),
    make_pair('0','9'),
    make_pair('-','0'),
    make_pair('=','-'),
    make_pair('[','P'),
    make_pair(']','['),
    make_pair('\\',']'),
    make_pair(',','M'),
    make_pair('.',','),
    make_pair('/','.'),
    make_pair('W','Q'),
    make_pair('E','W'),
    make_pair('R','E'),
    make_pair('T','R'),
    make_pair('Y','T'),
    make_pair('U','Y'),
    make_pair('I','U'),
    make_pair('O','I'),
    make_pair('P','O'),
    make_pair('S','A'),
    make_pair('D','S'),
    make_pair('F','D'),
    make_pair('G','F'),
    make_pair('H','G'),
    make_pair('J','H'),
    make_pair('K','J'),
    make_pair('L','K'),
    make_pair(';','L'),
    make_pair('X','Z'),
    make_pair('C','X'),
    make_pair('V','C'),
    make_pair('B','V'),
    make_pair('N','B'),
    make_pair('M','N'),
    make_pair('\'',';')
};

char getLeft(char c){
    if('1'<c && c <= '9')
        return c-1;
    auto it = mapToLeft.find(c);
    if(it==mapToLeft.end())
        return c;
    return it->second;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string line;
    while(getline(cin,line)){
        for(char x:line)
            cout << getLeft(x);
        cout << "\n";
    }
    return 0;
}