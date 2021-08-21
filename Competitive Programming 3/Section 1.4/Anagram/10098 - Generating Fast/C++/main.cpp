#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    string line;
    cin >> n;
    while(n--){
        cin >> line;
        sort(line.begin(),line.end());
        do{
            cout << line << "\n";
        }while(next_permutation(line.begin(),line.end()));
        cout << "\n";
    }
    return 0;
}