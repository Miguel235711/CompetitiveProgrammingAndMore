#include <bits/stdc++.h>

using namespace std;

int arr[1000000],l=0,r=0;

void push(int x){
    arr[r++]=x;
}
int pop(){
    return arr[l++];
}
int size(){
    return r - l;
}
bool empty(){
    return !size();
}
int front(){
    return arr[l];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,xi;
    cin >> n;
    while(n--){
        cin >> xi;
        push(xi);
    }
    while(!empty()){
        cout << pop();
        if(!empty())
            cout << " ";
    }
    cout << "\n";
}