#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string line; 
    int time = 0 ; 
    while(getline(cin,line)){
        string transLine;
        for(char x: line){
            if(x=='"'){
                if(time&1){
                    transLine.append("''");
                }else{
                    transLine.append("``");
                }
                time = (time+1) & 1 ; 
            }else{
                transLine.push_back(x);
            }
        }
        cout << transLine << "\n";
    }
    return 0;
}