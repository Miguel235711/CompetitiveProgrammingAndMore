#include<bits/stdc++.h>
#define lim 1008

using namespace std;

int arr[lim],memo[lim],from[lim],n;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ; 
    for(int i = 1 ; i <= n ; i ++)
        cin >> arr[i];
    arr[0]=INT_MIN;
    for(int i = n ; i > -1 ; i --){
        for(int j = i + 1 ; j <= n ; j ++)
            if(arr[j]>arr[i] && memo[j] > memo[i]) /// be careful
                memo[i] = memo[j], from[i] = j;
        memo[i]++;
    }
    cout << memo[0]-1 << "\n";
    for(int i = 0 ;from[i]; i = from[i])
        cout << arr[from[i]] << " ";
    cout << "\n";
    return 0;
}