#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<int> arr;
    int mini = 100 , maxi = 0;
    string s;
    for(int i = 0 ; cin >> s ; i ++)
        arr.push_back(stoi(s)) , mini = min(mini,arr[i]) , maxi = max(maxi,arr[i]);
    vector<int> bucket(maxi-mini+1);
    for(size_t i = 0 ; i < arr.size() ; i ++)
        bucket[arr[i]-mini]++;
    for(int i = mini ; i <= maxi ; i ++)
        while(bucket[i-mini]--)
            cout << i << " " ; 
    cout << "\n";
    return 0;
}