#include <bits/stdc++.h>

using namespace std;

int m[108][108];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j++){
            cin >> m[i][j];
        }
    }
    for(int k = 0 ; k < n ; k ++){
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j ++){
                m[i][j] = min(m[i][j],m[i][k]+m[k][j]);
            }
        }
    }
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j++){
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}