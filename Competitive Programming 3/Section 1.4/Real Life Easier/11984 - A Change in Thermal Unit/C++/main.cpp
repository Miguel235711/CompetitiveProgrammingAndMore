#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,C,d;
    cin >> t;
    for(int cs = 1 ; cs <= t ; cs++){
        cin >> C >> d;
        printf("Case %d: %.2f\n",cs,C+(float)5*d/9);
    }
    return 0;
}