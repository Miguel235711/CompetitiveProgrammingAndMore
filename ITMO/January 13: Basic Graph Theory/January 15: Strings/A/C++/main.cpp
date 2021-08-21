#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p(n);
    for(int i = 1 ; i < n ; i ++){
        int x = p[i-1];
        for(;x&&s[x]!=s[i];x=p[x-1]);
        if(s[x]==s[i])
            x++;
        p[i]=x;
    }
    for(int x : p)
        cout << x << " ";
    cout << "\n";
    return 0;
}