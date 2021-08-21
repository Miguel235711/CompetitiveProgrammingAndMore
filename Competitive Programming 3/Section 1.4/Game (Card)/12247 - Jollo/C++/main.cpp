#include<bits/stdc++.h>

using namespace std;

int princess[3],prince[2];
bool defeatedMe[3],taken[52];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(1){
        memset(defeatedMe,0,sizeof(defeatedMe));
        memset(taken,0,sizeof(taken));
        for(int i = 0 ; i < 3 ; i ++){
            cin >> princess[i];
            if(!princess[i])
                return 0;
            taken[princess[i]-1]=true;
        }
        sort(princess,princess+3);
        int index = 0,lost = 0;
        for(int i = 0 ; i < 2 ; i ++){
            cin >> prince[i];
            taken[prince[i]-1]=true;
        }
        sort(prince,prince+2);
        for(int i = 0 ; i < 2 ; i ++){
            for(;index<3&&princess[index]<prince[i];index++);
            if(index<3){
                defeatedMe[index]=true;
                index++;
                lost++;
            }
        }
        int ans=-1;
        if(lost==0){
            //smallest not taken card
            for(int i = 0 ; i < 52 ;i++){
                if(!taken[i]){
                    ans=i+1;
                    break;
                }
            }
        }else if(lost==1){
            //greatest one to defeat
            for(int i = 2 ; i > -1 ; i --){
                if(!defeatedMe[i]){
                    ans=princess[i]+1;
                    for(;ans<=52&&taken[ans-1];ans++);
                    if(ans>52)
                        ans=-1;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}