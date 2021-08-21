#include <bits/stdc++.h>
#define maxLength 10

using namespace std;

int n;
char arr[maxLength];

void initializeArr(){
    for(int i = 0 ; i < n ; i ++){
        arr[i]='A'+i;
    }
}

void printArr(){
    cout << "{";
    for(int i = 0 ; i < n ; i ++){
        cout << "'" << arr[i] << "'";
        if(i+1<n){
            cout << ", ";
        }
    }
    cout << "}";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    initializeArr();
    do{
        printArr();
    }while(next_permutation(arr,arr+n));
    return 0;
}