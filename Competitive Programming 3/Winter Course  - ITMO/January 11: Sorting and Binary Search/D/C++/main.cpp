#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m,x;
    map<int,int> bucket;
    cin >> n ; 
    while(n--){
        cin >> x;
        bucket[x]++;
    }
    cin >> m ;
    while(m--)
        cin >> x , cout << bucket[x] << "\n";
    return 0;
}