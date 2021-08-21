#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z(n);
    int l=0,r=0;
    for(int i = 1 ; i < n ; i ++){
        int k = 0 ;
        if(i<r)
            k = min (z[i-l],r-i);
        while(i+k<n && s[k]==s[i+k])
            k++;
        z[i]=k;
        if(r<i + z[i])
            l=i,r=i+z[i];
    }
    int ans = n;
    for(int i = 1 ; i < n ; i ++){
        if(n%i==0 && z[i]+i==n){
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}