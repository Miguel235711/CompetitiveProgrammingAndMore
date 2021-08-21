#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int k ;
    while(cin>>k,k){
        int n,m;
        cin >> n >> m ; 
        while(k--){
            int x,y;
            cin >> x >> y ; 
            if(x==n||y==m){
                cout << "divisa";
            }else if(y>m){
                if(x<n){
                    cout << "NO";
                }else{
                    cout << "NE";
                }
            }else{
                if(x<n){
                    cout << "SO";
                }else{
                    cout << "SE";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}