#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t ; 
    cin >> t ;
    cout << "Lumberjacks:\n";
    while(t--){
        int last,number;
        bool negativeDif=false,positiveDif=false;
        cin >> last;
        for(int i = 1 ; i < 10 ; i ++){
            cin >> number;
            if(number-last>0){
                positiveDif = true;
            }else if(number-last<0){
                negativeDif = true;
            }
            last = number;
        }
        cout << (positiveDif^negativeDif?"Ordered":"Unordered") << "\n";
    }
}