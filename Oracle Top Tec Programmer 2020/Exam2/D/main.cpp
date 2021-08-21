#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int w,n;
    int64_t area=0;
    cin >> w >> n ; 
    for(int i = 0 ; i < n ; i ++){
        int a,b;
        cin >> a >> b ; 
        area += a*b;
    }
    cout << area / w << "\n" ; 
    return 0;
}