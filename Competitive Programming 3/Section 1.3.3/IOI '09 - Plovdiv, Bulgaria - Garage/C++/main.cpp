#include <bits/stdc++.h>

#define maxCars 2002

using namespace std;

int costPerKilo[102],weight[maxCars],slotTaken[maxCars];
priority_queue< int,vector<int>,greater<int> > available;
queue<int> waitingLine;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m,cost=0;
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i ++){
        cin >> costPerKilo[i];
        available.push(i);
    } 
    for(int i = 1 ; i <= m ; i ++){
        cin >> weight[i];
    }
    for(int m2 = m<<1; m2;m2--){
        int car;
        cin >> car;
        if(car < 0)
            available.push(slotTaken[-car]);
        else{
            waitingLine.push(car);
        }
        while(!available.empty()&&!waitingLine.empty()){
            int slot = available.top(), carRemoved = waitingLine.front();
            available.pop(),waitingLine.pop();
            cost += costPerKilo[slot] * weight[carRemoved];
            slotTaken[carRemoved] = slot;
        }
    }
    cout << cost << "\n";
    return 0;
}