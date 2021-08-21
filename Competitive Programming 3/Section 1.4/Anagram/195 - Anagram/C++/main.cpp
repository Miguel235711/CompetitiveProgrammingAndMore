#include<bits/stdc++.h>

using namespace std;

string line;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int c;
    cin >> c;
    auto compareF = [](char a,char b){
        auto aP = tolower(a) , bP = tolower(b);
        return aP==bP ? a < b : aP < bP;
    };
    while(c--&&cin>>line){
        sort(line.begin(),line.end(),compareF);
        do cout << line << "\n";
        while(next_permutation(line.begin(),line.end(),compareF));
    }
    return 0;
}