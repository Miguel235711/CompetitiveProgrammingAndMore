#include <bits/stdc++.h>

using namespace std;

int matrix[108][108],n,m,a,b;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m ;
    while(m--){
        cin >> a >> b ;
        a--,b--; 
        matrix[a][b]=matrix[b][a]=1;
    }
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
    return 0;
}