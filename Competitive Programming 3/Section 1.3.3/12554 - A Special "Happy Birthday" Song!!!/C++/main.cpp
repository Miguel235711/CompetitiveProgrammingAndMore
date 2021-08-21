#include<bits/stdc++.h>

using namespace std;

string song[4]={
    "Happy",
    "birthday",
    "to",
    "you"
},people[100];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n ; 
    cin >> n ; 
    for(int i = 0 ; i < n ; i ++){
        cin >> people[i];
    }
    int lines = ceil((float)n / 16)*16;
    for(int moment = 0 ; moment < lines ; moment++){
        cout << people[moment%n] << ": " << (moment%16!=11 ? song[moment%4] : "Rujia") << "\n";
    }
    return 0;
}