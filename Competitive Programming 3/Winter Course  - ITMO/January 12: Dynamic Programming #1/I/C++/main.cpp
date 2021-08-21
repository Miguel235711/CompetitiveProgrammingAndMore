#include<bits/stdc++.h>

#define inf 1000000

using namespace std;

int memo[1000008];
int from[1000008];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n ; 
    cin >> n ;
    memo[n]=0; 
    for(int i = n - 1 ; i ; i --){
        int by2 = i*2 > n ? inf : memo[i*2], by3 = i*3 > n ? inf : memo[i*3], inc = memo[i+1]; ///0 -> by2, 1 -> by3, 2 -> inc
        if(inc<=by2 && inc <= by3)
            from[i] = i + 1; 
        if(by2<=inc && by2 <= by3)
            from[i] = i * 2; 
        if(by3<= inc && by3 <= by2)
            from[i] = i * 3; 
        memo[i] = 1 + min(min(by2,by3),inc) ;
    }
    cout << memo[1]<<"\n";
    for(int current = 1 ; current ; current = from[current])
        cout << current << " ";
    cout << "\n";
    return 0;
}