#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int64_t merge_sort(int l , int r){
    /// [l,r)
    if(r-l==1)
        return 0;
    ///split and sort separately
    int mid = (l+r)/2;
    int64_t swaps = merge_sort(l,mid) + merge_sort(mid,r);
    //merge both in auxilary array
    vector<int> merged;
    for(int i = l , j = mid ; i < mid || j < r;)
        if(j == r || (i < mid && arr[i]<arr[j]))
            merged.push_back(arr[i++]);
        else{
            swaps += mid - i ; 
            merged.push_back(arr[j++]);
        }
    for(int i = l ; i < r ; i ++)
        arr[i] = merged[i-l];
    return swaps;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n ; 
    arr.resize(n);
    for(int i = 0 ; i < n ; i ++)
        cin >> arr[i];
    cout << merge_sort(0,n) << "\n";
    return 0;
}