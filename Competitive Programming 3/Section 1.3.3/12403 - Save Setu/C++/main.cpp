#include <iostream>

using namespace std;

int t,k,x;
string com;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> com;
        if(com[0]=='d'){
            cin >> x ; 
            k+=x;
        }else{
            cout << k << "\n";
        }
    }
    return 0;
}