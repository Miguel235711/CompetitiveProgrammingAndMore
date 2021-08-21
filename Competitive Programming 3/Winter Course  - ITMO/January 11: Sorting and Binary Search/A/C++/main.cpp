#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n ;
    vector<int> v;
    v.resize(n);
    for(int i = 0; i < n ; i ++)
        cin >> v[i];
    for(int i = 0 ; i < n ; i ++)
        for(int j = i + 1 ; j < n ; j ++)
            if(v[j]<v[i])
                swap(v[j],v[i]);
    for(int i = 0 ; i < n ; i ++)
        cout << v[i] << " " ; 
    cout << "\n";
    return 0;
}