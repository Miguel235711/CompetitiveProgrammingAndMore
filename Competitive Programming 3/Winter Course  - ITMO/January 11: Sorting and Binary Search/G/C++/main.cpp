#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n ; 
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    sort(arr.begin(),arr.end());
    int k , l , r ; 
    cin >> k ; 
    while(k--){
        cin >> l >> r;
        cout << upper_bound(arr.begin(),arr.end(),r) - lower_bound(arr.begin(),arr.end(),l) << " ";
    }
    cout << "\n";
    return 0;
}