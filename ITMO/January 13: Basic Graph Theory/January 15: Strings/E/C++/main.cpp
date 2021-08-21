#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s,t;
    cin >> s >> t;
    int sSize = s.size();
    string concat = s+"#"+t;
    int concatSize = concat.size();
    vector<int> p(concatSize);
    for(int i = 1 ; i < concatSize ; i ++){
        int x = p[i-1];
        for(;x&&concat[x]!=concat[i];x=p[x-1]);
        if(concat[x]==concat[i])
            x++;
        p[i]=x;
    }
    vector<int>ans;
    for(int i = sSize+1;i<concatSize;i++)
        if(p[i]==sSize)
            ans.push_back(i-sSize-sSize+1);
    cout << ans.size() << "\n";
    for(int x : ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}