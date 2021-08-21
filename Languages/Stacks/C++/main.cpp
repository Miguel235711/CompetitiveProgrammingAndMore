#include <bits/stdc++.h>

using namespace std;

stack<int> myStack, myStack2;

int main(){
    int n,ni;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>ni;
        myStack2.push(ni);
    }
    myStack2.swap(myStack);
    cout<<"Size: "<<myStack.size()<<"\n";
    cout<<"Popping: ";
    while(!myStack.empty()){
        cout<<myStack.top()<<" ";
        myStack.pop();
    }
    return 0;
}
