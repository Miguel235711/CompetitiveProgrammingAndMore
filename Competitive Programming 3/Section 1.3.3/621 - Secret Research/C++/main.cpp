#include<iostream>

using namespace std;

int n;
string s; 

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ; 
    while(n--){
        cin >> s ; 
        if(s=="1"||s=="4"||s=="78"){
            cout << '+';
        }else if(s[s.size()-2]=='3'&&s[s.size()-1]=='5'){
            cout << '-';
        }else if(s[0]=='9'&&s[s.size()-1]=='4'){
            cout << '*';
        }else{
            cout << '?';
        }
        cout << "\n";
    }
    return 0;
}