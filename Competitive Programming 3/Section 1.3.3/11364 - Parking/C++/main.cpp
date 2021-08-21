#include <bits/stdc++.h>

using namespace std;

int t,n,x;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int minimum = 99 , maximum = 0 ;
        for(int i = 1; i <= n ; i ++){
            cin >> x ; 
            minimum = min(minimum,x), maximum = max(maximum,x);
        }
        cout << maximum - minimum + maximum - minimum << "\n";
    }
    return 0;
}