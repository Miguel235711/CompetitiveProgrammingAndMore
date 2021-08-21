#include<bits/stdc++.h>

using namespace std;

bool isTurnedOn[22];
int consumption[22];
int n,m,c;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int cs=1;
    while(cin>>n>>m>>c,n||m||c){
        memset(isTurnedOn,0,sizeof(isTurnedOn));
        cout << "Sequence " << cs++<<"\n";
        for(int i = 1 ; i <= n ; i ++)
            cin >> consumption[i];
        int consumed = 0, maxConsumed=0;
        while(m--){
            int toggleI;
            cin >> toggleI;
            consumed+=consumption[toggleI]*(isTurnedOn[toggleI]?-1:1);
            isTurnedOn[toggleI]=!isTurnedOn[toggleI];
            maxConsumed=max(maxConsumed,consumed);
        }
        cout << "Fuse was " << (maxConsumed>c?"blown":"not blown") << ".\n";
        if(maxConsumed<=c)
            cout << "Maximal power consumption was " << maxConsumed << " amperes.\n";
        cout << "\n";
    }
    return 0;
}