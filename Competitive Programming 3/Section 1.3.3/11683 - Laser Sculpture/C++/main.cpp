#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int A,C;
    while(cin>>A,A){
        cin >> C;
        int last=A,ans=0,current;
        for(int i = 0 ; i < C ; i ++){
            cin >> current;
            if(current>last){
                ans+=current-last;
            }
            last = current;
        }
        cout << ans+A-last << "\n";
    }
    return 0;
}