#include<bits/stdc++.h>

using namespace std;

bool isIgnored(char x){
    return x < 'a' || x > 'z';
}

int sqrtLength;

int specialPos(int i){
    return sqrtLength * (i%sqrtLength) + i / sqrtLength;
}
bool magicPalindrome(string s){
    for(size_t i1 = 0 ; i1 < s.size() ; i1 ++){
        size_t i3 = s.size()-1-i1 , i2 = specialPos(i1) , i4 = specialPos(i3);
        if(s[i1]!=s[i2]||s[i1]!=s[i3]||s[i1]!=s[i4])
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    string s;
    for(int cs = 0 ; cs < t; cs ++ ){
        getline(cin,s);
        s.erase(remove_if(s.begin(),s.end(),isIgnored),s.end());
        sqrtLength = sqrt(s.size());
        cout << "Case #" << cs+1 << ":\n" << (sqrtLength*sqrtLength==s.size()&&magicPalindrome(s)?to_string(sqrtLength):"No magic :(") << "\n";
    }
}