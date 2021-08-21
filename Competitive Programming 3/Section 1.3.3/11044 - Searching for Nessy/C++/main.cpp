#include <iostream>

using namespace std;

int extraDiv(int a, int b){
    return a%b?1:0;
}

int operation(int a){
    a-=2;
    return a/3 + extraDiv(a,3);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t ; 
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m ; 
        cout << operation(n) * operation(m) << "\n";
    }
    return 0;
}