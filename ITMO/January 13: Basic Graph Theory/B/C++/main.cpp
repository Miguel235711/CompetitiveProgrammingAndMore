#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,ans=0,x; 
    cin  >> n ; 
    for(int i  = 0 ; i < n ; i ++)
        for(int j = 0 ; j < n ; j ++)
            cin >> x , ans +=x;
    cout << (ans >> 1) << "\n"; 
    return 0;
}