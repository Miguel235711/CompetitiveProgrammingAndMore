#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(const string &s){
    int lim = s.size()>>1;
    for(int i=0;i<lim;i++)
        if(s[i]!=s[s.size()-i-1])
            return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    while(cin>>s){
        set<string> differentPs;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                auto substring = s.substr(i,j-i+1);
                if(isPalindrome(substring))
                    differentPs.insert(substring);
            }
        }
        cout << "The string '" << s << "' contains " << differentPs.size() << " palindromes.\n"; 
    }
    return 0;
}