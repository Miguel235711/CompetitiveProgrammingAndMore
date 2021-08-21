#include <bits/stdc++.h>

using namespace std ; 

int n, x;
set<int>mySet ; 

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ; 
    while(n--){
        cin >> x ; 
        mySet.insert(x);
    }
    for(auto it = mySet.begin(); it != mySet.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";
    return 0 ; 
}