#include <bits/stdc++.h>

using namespace std;

bool matrix[108][108];
bool valid = true; 
int n; 

void f(){
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < n ; j ++)
            if(matrix[i][j]!=matrix[j][i] || (i==j&&matrix[i][j])){
                valid = false;
                return;
            }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ;
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < n ; j ++)
            cin >> matrix[i][j];
    f();
    cout << (valid?"YES":"NO") << "\n";
    return 0;
}