#include <iostream>

using namespace std;

int sumDigits(int x){
    int ans = 0;
    for(;x;x/=10){
        ans+=x%10;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n ; 
    while(cin >> n,n){ 
        while(n>9){
            n = sumDigits(n);
        }
        cout << n << "\n";
    }
    return 0;
}