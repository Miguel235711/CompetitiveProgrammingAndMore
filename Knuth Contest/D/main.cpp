#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n ;
    int acum = 0 , last = 0 ; 
    for(int i = 1; i <= n ; i ++){
        int x = round(sqrt(i));
        if(x!=last)
            acum=1,last=x;
        else
            acum++;
        cout << "i: " << i << " -> " << x << " => " <<  acum << "\n";
    }
    return 0;
}