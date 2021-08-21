#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,x;
    cin >> t ; 
    for(int cs = 1 ; cs<=t ; cs++){
        string ans = "good";
        for(int i = 0 ; i < 3 ; i ++){
            cin >> x ; 
            if(x>20){
                ans="bad";
            }
        }
        cout << "Case " << cs << ": " << ans << "\n";
    }
    return 0;
}