#include<iostream>

using namespace std;

int n,farmers,sz,animals,friendliness;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    while(n--){
        int64_t ans = 0 ;
        cin >> farmers ; 
        while(farmers--){
            cin >> sz >> animals >> friendliness;
            ans += (int64_t) sz * friendliness;
        }
        cout << ans << "\n";
    }
    return 0;
}