#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,s,d,s1,s2;
    cin >> n;
    while(n--){
        cin >> s >> d;
        s2 = (d-s) / -2;
        s1 = s-s2;
        cout << ((d-s)&1||s1<0||s2<0?"impossible":to_string(s1)+" "+to_string(s2)) << "\n";  
    }
    return 0;
}