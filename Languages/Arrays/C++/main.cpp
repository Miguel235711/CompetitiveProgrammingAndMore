#include<bits/stdc++.h>
#define lim 1000000
using namespace std;
int arr[lim];

template<class T>
void print(T *a){
  for(int i = 0 ; i < 10 ; i++)
    cout << a[i] << " ";
  cout<<"\n";
}
template<class T>
void print(const vector<T>&a){
  for(T e:a)
    cout<<e<<" ";
  cout<<"\n";
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int arr2[lim];
  memset(arr2,0,sizeof(arr2));
  print(arr2);
  int *arr3=new int[lim];
  memset(arr3,0,sizeof(arr3));
  print(arr3);
  vector<int>arr4(4,-2);
  print(arr4);
  arr4.push_back(3);
  print(arr4);
  arr4.pop_back();
  print(arr4);
  arr4.resize(10,1);
  print(arr4);
  arr4.resize(9,100);
  print(arr4);
  cout<<arr4.size()<<"\n";
  arr4.insert(arr4.begin()+2,3);
  print(arr4);
  arr4.erase(arr4.begin()+2,arr4.begin()+3);
  print(arr4);
  return 0;
}