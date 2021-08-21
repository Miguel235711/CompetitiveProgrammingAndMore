#include <bits/stdc++.h>

using namespace std;

bool taken[10000];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int k,m;
    while(cin>>k,k){
        cin>>m;
        memset(taken,false,sizeof(taken));
        for(int i = 0 ; i < k ; i ++){
            int number;
            cin >> number;
            taken[number]=true;
        }
        bool isYes=true;
        for(int i = 0 ; i < m; i ++){
            int c,r;
            cin >> c >> r ;
            for(int j = 0 ; j < c ; j ++){
                int number;
                cin >> number;
                if(taken[number]){
                    r--;
                }
            }
            if(r>0){
                isYes=false;
            }
        }
        cout << (isYes?"yes":"no") << "\n";
    }
    return 0;
}