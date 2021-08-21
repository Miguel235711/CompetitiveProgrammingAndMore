#include <iostream>

using namespace std;

string line;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n ;
    for(int cs = 1;cin >> n && n ;cs ++){
        int ans = 0, x;
        for(int i = 0 ; i < n ; i ++){
            cin >> x ; 
            ans += x ? 1 : -1 ; 
        }
        cout << "Case " << cs << ": " << ans << "\n";
    }
    return 0;
}