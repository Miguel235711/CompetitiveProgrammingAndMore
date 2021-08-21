#include<bits/stdc++.h>

using namespace std;

queue<int> myQueue;

int main(){
  int n,x;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> x;
    myQueue.push(x);// O(1)
  }
  queue<int> myQueue2;
  myQueue2.push(2);// O(1)
  myQueue2.swap(myQueue);// O(1)
  cout<<myQueue2.size()<<"\n"; // O(1)
  cout<<myQueue2.front()<<"\n"; // O(1)
  cout<<myQueue.size()<<"\n";// O(1)
  cout<<myQueue.back()<<"\n";// O(1)
  cout<<myQueue.front()<<"\n";// O(1)
  cout<<"elements popped out:\n";
  while(!myQueue.empty()/*O(1)*/){
    cout << myQueue.front() << "\n";// O(1) 
    myQueue.pop();// O(1)
  }
}