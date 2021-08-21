#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    stack<string> numbers;
    string x;
    cin >> n ;
    while(n--)
        cin >> x, numbers.push(x);
    while(!numbers.empty())
        cout << numbers.top() << " " , numbers.pop(); 
    cout << "\n";
    return 0;
}