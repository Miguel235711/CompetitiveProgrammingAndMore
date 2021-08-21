#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int remain,x;
    for(int cs = 1 ;cin >>remain && remain;cs++){
        cout << "Output for data set " << cs << ", " << remain << " bytes:\n";
        int j=0;
        for(int i=0,acum5=0;remain;i=(i+1)%5,j++){
            cin>>x;
            remain-=x;
            acum5+=x;
            if(i==4){
                //process acum5
                auto remain5 = remain*5 ;
                cout << "   Time remaining: " << (acum5 ? (to_string(remain5/acum5+(remain5%acum5?1:0))+" seconds"):"stalled") << "\n";
                acum5=0;
            }
        }
        cout << "Total time: " << j << " seconds\n\n";
    }
    return 0;
}