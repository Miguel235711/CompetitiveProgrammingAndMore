#include <iostream>

using namespace std;

int n ;
string line;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ;
    while(n--){
        cin >> line;
        if(line.size()==5){
            cout << '3';
        }else if(((line[0]=='o'||line[1]=='n')&&line[2]=='e')||(line[0]=='o'&&line[1]=='n')){
            cout << '1';
        }else{
            cout << '2';
        }
        cout << "\n";
    }
    return 0;
}