#include<bits/stdc++.h>
#define lim 90

using namespace std;

int arr[lim+1],N,B;
bool possible[lim];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>N>>B,N){
        for(int i=0;i<B;i++)
            cin>>arr[i];
        memset(possible,0,sizeof(possible));
        int remain=N;
        for(int i=0;i<B;i++)
            for(int j=i+1;j<B;j++)
                if(!possible[abs(arr[i]-arr[j])-1]){
                    possible[abs(arr[i]-arr[j])-1]=true;
                    remain--;
                }
        cout<<(remain?'N':'Y')<<'\n';
    }
    return 0;
}