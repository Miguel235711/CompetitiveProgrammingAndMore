#include<bits/stdc++.h>

using namespace std;

set<char> puntuaction = {
    '.',
    ',',
    '!',
    '?',
    ' '
};

bool palindrome(const string &s){
    for(int i = 0 , j = s.size()-1 ; i < j ; i++,j--){
        //ignore puntuactions
        for(;i<j&&puntuaction.find(s[i])!=puntuaction.end();i++);
        for(;i<j&&puntuaction.find(s[j])!=puntuaction.end();j--);
        //check if equivalent (ignoring casing)
        if(i<j&&tolower(s[i])!=tolower(s[j]))
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string sentence;
    while(getline(cin,sentence),sentence!="DONE"){
        cout << (palindrome(sentence)?"You won't be eaten!":"Uh oh..") << "\n";
    }
    return 0;
}