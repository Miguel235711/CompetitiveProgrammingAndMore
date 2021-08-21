#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x1,x2,y1,y2;
    while(cin>>x1>>y1>>x2>>y2,x1){
        cout << (x1==x2&&y1==y2?'0':(x1==x2||y1==y2||abs(x2-x1)==abs(y2-y1)?'1':'2')) << "\n";
    }
    return 0;
}