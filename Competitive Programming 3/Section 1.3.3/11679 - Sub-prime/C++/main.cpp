#include<bits/stdc++.h>

using namespace std;

int reserve[22];
int B,N,a,b,c;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> B >> N , B || N ){
        for(int i = 1 ; i <= B ; i ++ ){
            cin>>reserve[i];
        }
        for(int i = 1 ; i <= N ; i ++){
            cin >> a >> b >> c ; 
            reserve[a]-=c;
            reserve[b]+=c;
        }
        char ans = 'S';
        for(int i = 1 ; i <= B ; i ++){
            if(reserve[i]<0){
                ans='N';
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0 ; 
}