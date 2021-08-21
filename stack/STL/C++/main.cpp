#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    stack<int> st;
    int N,xi;
    cin >> N;
    while(N--){
        cin >> xi;
        st.push(xi);
    }
    cout << "elements:\n";
    while(!st.empty()){
        cout << st.top();
        st.pop();
        if(!st.empty())
            cout << " ";
    }
    cout << "\n";
    return 0;
}