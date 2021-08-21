#include <bits/stdc++.h>

#define maxLength 1000008

using namespace std; 

int n,arr[maxLength];

bool exists(int x){
    int l = 0 , r = n - 1 ; 
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(arr[mid]==x){
            return true;
        }else if(arr[mid]<x){
            l = mid + 1 ; 
        }else{
            r = mid - 1 ; 
        }
    }
    return arr[l] == x || arr[r] == x;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ; 
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }
    int val;
    cin >> val ; 
    cout << exists(val) << "\n";
    return 0;
}