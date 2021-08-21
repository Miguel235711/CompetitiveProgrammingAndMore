#include <bits/stdc++.h>

using namespace std;

int main(){
    string s ; 
    getline(cin,s);
    for(int i = 0 ; i < s.size() ; i ++){
        if(i>1&&isdigit(s[i])&&isdigit(s[i-1])&&islower(s[i-2])&&(i==2||s[i-3]==' ')&&(i+1==s.size()||s[i+1]==' ')){
            fill(s.begin()+i-2,s.begin()+i+1,'*');
        }
    }
    cout << s << "\n";
    return 0;
}