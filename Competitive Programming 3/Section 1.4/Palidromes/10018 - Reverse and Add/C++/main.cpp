#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(const string &s){
    int lim = s.size() >> 1;
    for(int i=0;i<lim;i++)
        if(s[i]!=s[s.size()-1-i])
            return false;
    return true;
}
string reverseAndAdd(const string &s){
    string sR = s;
    reverse(sR.begin(),sR.end());
    return to_string(stoul(s)+stoul(sR));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    string s;
    while(n--){
        cin >> s;
        int ite=0;
        for(;!isPalindrome(s);ite++)
            s = reverseAndAdd(s);
        cout << ite << " " << s << "\n";
    }
    return 0;
}