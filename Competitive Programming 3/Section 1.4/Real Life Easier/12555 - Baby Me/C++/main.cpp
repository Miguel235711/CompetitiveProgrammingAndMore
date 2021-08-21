#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,a;
    cin >> t;
    cin.ignore();
    string s;
    for(int cs = 1 ; cs <= t ; cs++){
        cin>>a;
        cin.ignore();
        getline(cin,s);
        int b = s.size()>4 ? s[4]-'0' : 0;
        cout << "Case " << cs << ": " << a/2.0 + b/20.0 << "\n"; 
    } 
    return 0;
}