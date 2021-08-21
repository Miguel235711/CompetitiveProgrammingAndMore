#include<bits/stdc++.h>
#define inf 5e12

using namespace std;

int n,arr[5008];
int64_t memo[5008];

int cost(int a,int b){
    return abs(a-b);
}

int main(){
    set<int> aS;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i],aS.insert(arr[i]);
    vector<int> sorted(aS.begin(),aS.end());
    int ss = sorted.size();
    for(int i = 0 ; i < n ; i ++){
        int64_t mini = inf;
        for(int j = 0 ; j < ss ; j++){
            mini = min(mini,memo[j]);
            memo[j] = mini + cost(arr[i],sorted[j]);
        }
    }
    int64_t ans = inf;
    for(int j = 0 ; j < ss ; j ++)
        ans = min(ans,memo[j]);
    cout << ans << "\n";
    return 0;
}