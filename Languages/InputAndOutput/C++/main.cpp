#include<iostream>

using namespace std;

int arr[1000002];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"(";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<(i+1<n?",":"");
    }
    cout<<")\n";
    return 0;
}