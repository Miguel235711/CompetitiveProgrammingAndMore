#include<bits/stdc++.h>

using namespace std ; 

int nA,nB,k,m,first,second,x;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> nA >> nB >> k >> m ; 
    for(int i =  1 ; i < k ; i ++ ){
        cin>> x ; 
    }
    cin >> first ; 
    int lim = nA-k + nB - m;
    for(int i = 1 ; i <= lim ; i++ ){
        cin >> x  ;
    }
    cin >> second ; 
    cout << (first < second ? "YES" : "NO") << "\n";
    return 0;
}