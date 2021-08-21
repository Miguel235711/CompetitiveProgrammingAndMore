#include <bits/stdc++.h>

using namespace std;

int a,b,x;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>a>>b,a){
        int pointer=0,amountA=0,amountB=0,last=0;
        vector<int>aArr;
        for(int i = 0 ; i < a ; i ++){
            cin >> x;
            if(last!=x){
                aArr.push_back(x);
                last=x;
            }
        }
        last=0;
        for(int i = 0 ; i < b;i++){
            cin >> x;
            if(x!=last){
                for(;pointer<aArr.size()&&aArr[pointer]<x;pointer++){
                    amountA++;
                }
                if(pointer==aArr.size()||aArr[pointer]!=x){
                    amountB++;
                }
                if(pointer<aArr.size()&&aArr[pointer]==x)
                    pointer++;
                last=x;
            }
        }
        amountA+= aArr.size()-pointer;
        cout << min(amountA,amountB) << "\n";
    }
    return 0;
}