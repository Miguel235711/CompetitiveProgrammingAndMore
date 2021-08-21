#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

void merge_sort(int l , int r){
    /// [l,r)
    if(r-l==1)
        return;
    ///split and sort separately
    int mid = (l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid,r);
    //merge both in auxilary array
    vector<int> merged;
    for(int i = l , j = mid ; i < mid || j < r;)
        if(j == r || (i < mid && arr[i]<arr[j]))
            merged.push_back(arr[i++]);
        else
            merged.push_back(arr[j++]);
    for(int i = l ; i < r ; i ++)
        arr[i] = merged[i-l];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n ; 
    arr.resize(n);
    for(int i = 0 ; i < n ; i ++)
        cin >> arr[i];
    merge_sort(0,n);
    for(int i = 0 ; i < n ; i ++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}