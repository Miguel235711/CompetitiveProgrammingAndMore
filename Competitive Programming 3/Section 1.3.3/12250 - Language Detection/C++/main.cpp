#include <bits/stdc++.h>

using namespace std;

map<string,string> wordToLanguage = {
    make_pair("HELLO","ENGLISH"),
    make_pair("HOLA","SPANISH"),
    make_pair("HALLO","GERMAN"),
    make_pair("BONJOUR","FRENCH"),
    make_pair("CIAO","ITALIAN"),
    make_pair("ZDRAVSTVUJTE","RUSSIAN")
};

string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int cs = 1 ; 
    while(getline(cin,s),s!="#"){
        cout << "Case " << cs++ << ": ";
        auto it = wordToLanguage.find(s);
        if(it==wordToLanguage.end()){
            cout << "UNKNOWN";
        }else{
            cout << it->second;
        }
        cout << "\n";
    }
    return 0;
}