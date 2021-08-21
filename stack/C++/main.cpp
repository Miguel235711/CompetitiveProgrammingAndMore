#include <bits/stdc++.h>

using namespace std;

int arr[1000008],lim = 0;

void push(int x){
    arr[lim++]=x;
}
int pop(){
    return arr[--lim];
}
int top(){
    return arr[lim-1];
}
int size(){
    return lim;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,xi;
    cin >> N ; 
    while(N--){
        cin >> xi;
        push(xi);
    }
    cout << "elements:\n";
    while(size()){
        cout << pop();
        if(size())
            cout << " ";
    }
    cout << "\n";
    return 0;
}