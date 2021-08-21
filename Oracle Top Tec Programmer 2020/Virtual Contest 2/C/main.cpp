#include<bits/stdc++.h>

using namespace std ; 

int t,n,m,a1,ai;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    while(t--){
        int sum = 0 ; 
        cin >> n >> m >> a1 ; 
        for(int i = 1 ; i < n ; i ++ ){
            cin >> ai ; 
            sum += ai ; 
        }
        cout << min(a1+sum,m) << "\n";
    }
    return 0;
}