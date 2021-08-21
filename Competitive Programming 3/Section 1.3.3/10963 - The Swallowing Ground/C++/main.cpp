#include<iostream>

using namespace std;

int t,n,y11,y2,dif;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    for(int cs = 0 ; cs < t ; cs++){
        if(cs!=0)
            cout << "\n";
        cin >> n ; 
        cin >> y11 >> y2 ; 
        dif = y11 - y2 ; 
        n--;
        string ans = "yes";
        while(n--){
            cin >> y11 >> y2 ; 
            if(y11-y2!=dif){
                ans = "no";
            }
        }
        cout << ans << "\n";
    }
    return 0;
}