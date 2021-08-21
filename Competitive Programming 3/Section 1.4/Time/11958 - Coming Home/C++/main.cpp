#include<bits/stdc++.h>

using namespace std;

int getDelta(int hi,int mi,int h,int m){
    return hi>h||(hi==h&&mi>m) ? (hi - h)*60 + mi - m : ((23-h)*60+60-m+hi*60+mi)%1440;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t ; 
    char g;
    cin >> t ;
    for(int cs = 1 ; cs <=t ; cs++){
        int k,h,m,hi,mi,extra;
        cin >> k >> h >> g >> m;
        int minTime = INT_MAX;
        for(int i = 0 ; i < k ; i ++){
            cin >> hi >> g >> mi >> extra;
            minTime=min(minTime,getDelta(hi,mi,h,m)+extra);
        }
        cout << "Case " << cs << ": " << minTime << "\n";
    } 
    return 0;
}