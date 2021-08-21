#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t ; 
    for(int cs = 1 ; cs <= t ; cs++){
        int mCost = 0,jCost = 0 ;
        int n,timeI ; 
        cin >> n ; 
        while(n--){
            cin >> timeI;
            mCost+=(timeI/30+1)*10;
            jCost+=(timeI/60+1)*15;
        }
        cout << "Case " << cs << ": ";
        if(mCost<jCost){
            cout << "Mile " << mCost;
        }else if(mCost==jCost){
            cout << "Mile Juice " << mCost;
        }else{
            cout << "Juice " << jCost;
        }
        cout << "\n";
    }
    return 0;
}