#include<bits/stdc++.h>

using namespace std;

vector<double> positions;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n,m;
    cin >> n >> m >> t ;
    for(int i = 0 ; i < t ; i ++){
        int xi,yi;
        cin >> xi >> yi;
        positions.push_back(yi); 
    }
    sort(positions.begin(),positions.end());
    double lim = positions[0]+150*2;
    int ans = 1;
    for(int i = 1 ; i<positions.size();i++){
        if(positions[i]>lim){
            lim = positions[i]+150*2;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}