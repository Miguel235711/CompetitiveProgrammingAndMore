#include<iostream>

using namespace std;

int a,b;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>a>>b,a!=-1){
        if(b>a)
            swap(a,b);
        cout << min(a-b,100-a+b) << "\n";
    }
    return 0;
}