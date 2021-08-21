#include<bits/stdc++.h>

using namespace std;

string ans[2][2] = {{"is not a palindrome","is a mirrored string"},{"is a regular palindrome","is a mirrored palindrome"}};
map<char,char> reversed = {
    make_pair('A','A'),
    make_pair('E','3'),
    make_pair('H','H'),
    make_pair('I','I'),
    make_pair('J','L'),
    make_pair('L','J'),
    make_pair('M','M'),
    make_pair('O','O'),
    make_pair('S','2'),
    make_pair('T','T'),
    make_pair('U','U'),
    make_pair('V','V'),
    make_pair('W','W'),
    make_pair('X','X'),
    make_pair('Y','Y'),
    make_pair('Z','5'),
    make_pair('1','1'),
    make_pair('2','S'),
    make_pair('3','E'),
    make_pair('5','Z'),
    make_pair('8','8')
};
int getPalindromeValue(const string & s){
    auto lim = s.size() >> 1;
    for(size_t i=0;i<lim;i++)
        if(s[i]!=s[s.size()-1-i])
            return 0;
    return 1;
}
string getMirroredString(string s){
    for(size_t i=0;i<s.size();i++){
        auto it = reversed.find(s[i]);
        if(it==reversed.end())
            return "";
        else
            s[i]=it->second;
    }
    return s;  
}
int getMirroredPalindromeValue(const string &s){
    string mirroredString = getMirroredString(s);
    if(mirroredString.empty())
        return 0;
    //compared if mirroredString backwards is the same as s
    for(size_t i=0;i<s.size();i++)
        if(s[i]!=mirroredString[s.size()-1-i])
            return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    while(cin>>s){
        int isPalindrome = getPalindromeValue(s), isMirrored = getMirroredPalindromeValue(s);
        cout << s << " -- " << ans[isPalindrome][isMirrored] << ".\n\n";
    }
    return 0;
}