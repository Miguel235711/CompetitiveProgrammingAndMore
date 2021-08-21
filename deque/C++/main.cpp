#include<bits/stdc++.h>
#define maxSize 1000000

using namespace std;

int l = maxSize / 2, r = l,arr[maxSize],sz = 0;

int size(){
    return sz;
}
bool empty(){
    return !sz;
}

void push_l(int x){
    sz++;
    arr[empty() ? l : --l]=x;
}
void push_r(int x){
    sz++;
    arr[empty() ? r : ++r]=x;
}
int pop_l(){
    sz--;
    return arr[l++];
}
int pop_r(){
    sz--;
    return arr[r--];
}
int front(){
    return arr[l];
}
int back(){
    return arr[r];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,xi;
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
        cin >> xi;
        if(i&1)
            push_r(xi);
        else
            push_l(xi);
    }
    for(int i = 0 ; !empty() ; i ++){
        cout << (i&1 ? pop_r() : pop_l());
        if(!empty())
            cout << " ";
    }
    cout << "\n";
    return 0;
}