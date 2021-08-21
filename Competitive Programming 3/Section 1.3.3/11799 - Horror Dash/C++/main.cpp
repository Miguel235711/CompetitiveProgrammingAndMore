#include<iostream>

using namespace std;

int t,n,x;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    for(int cs = 1 ; cs <= t ; cs ++){
        cin >> n ; 
        int maxi = 1 ; 
        while(n--){
            cin >> x ; 
            maxi = max(x,maxi);
        }
        cout << "Case " << cs << ": " << maxi << "\n";
    }
    return 0;
}