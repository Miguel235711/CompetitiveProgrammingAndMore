#include <iostream>

using namespace std;

string line;

int countDigits(int number){
    int ans=0;
    for(;number;ans++,number/=10);
    return ans;
}

void countUntil1(int number){
    int ans = 0 ; 
    for(;number!=1;ans++,number = countDigits(number));
    cout << ans+2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(getline(cin,line),line[0]!='E'){
        if(line.size()==1&&line[0]=='1'){
            cout << "1\n";
        }else{
            countUntil1(line.size());
        }
    }
    return 0;
}