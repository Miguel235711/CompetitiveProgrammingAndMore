#include<bits/stdc++.h>

using namespace std;

string nextPal[1440];

int toInteger(int h,int m){
    return h*60+m;
}
string toSingleString(int x){
    return (x<10 ? "0" : "") + to_string(x);  
}
string toString(int h,int m){
    return toSingleString(h) + toSingleString(m);
}
string toFString(int h,int m){
    return toSingleString(h) + ":" + toSingleString(m);
}
bool isPalindrome(int h,int m){
    auto s = toString(h,m);
    if(s[0]=='0'){
        s.erase(s.begin(),find_if(s.begin(),s.end(),
            [](char x){
                return x!='0';
            })
        );
    }
    for(size_t i=0;i<s.size();i++)
        if(s[i]!=s[s.size()-i-1])
            return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string nextP = "00:00";
    for(int h = 23 ; h > -1  ; h--){
        for(int m = 59 ; m > -1 ; m --){
            nextPal[toInteger(h,m)]=nextP;
            if(isPalindrome(h,m))
                nextP=toFString(h,m);
        }
    }
    int t;
    cin >> t ; 
    while(t--){
        int h,m;
        char g;
        cin >> h >> g >> m;
        cout << nextPal[toInteger(h,m)] << "\n";
    }
    return 0;
}