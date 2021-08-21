#include<bits/stdc++.h>

using namespace std;

int arr[50][2],n;
string part[2] = {"front","back "};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>n&&n){
        memset(arr,0,sizeof(arr));
        int lim = ((n-1)/4+1)<<1 , lim2 = lim << 1;
        int stLim = min(n,lim);
        for(int i = 0 ; i < stLim; i++)
            arr[i][!(i&1)]=i+1;    
        if(n>lim)
            for(int i = lim2 - n ; i < lim ; i++)
                arr[i][i&1] = lim2 - i ;
        cout << "Printing order for " << n << " pages:\n"; 
        for(int i = 0 ; i < lim ; i ++){
            if(arr[i][0]||arr[i][1]){
                cout << "Sheet " << i/2+1 << ", " << part[i&1] << ": ";
                for(int j = 0 ; j < 2 ; j ++){
                    if(j)
                        cout << ", ";
                    cout << (arr[i][j] ? to_string(arr[i][j]): "Blank");
                }
                cout << "\n";
            }
        }
    }
    return 0;
}