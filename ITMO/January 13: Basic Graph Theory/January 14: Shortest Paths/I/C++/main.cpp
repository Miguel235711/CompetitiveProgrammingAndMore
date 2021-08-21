#include <bits/stdc++.h>
 
using namespace std;
 
int64_t m[108][108],last[108][108];
 
void restoreCycle(int64_t x){
    vector<int64_t> ans;
    ans.push_back(x);
    for(int64_t c = last[x][x];c!=x;c=last[c][x])
        ans.push_back(c);
    cout << ans.size()<< "\n";
    for(int64_t e:ans)
        cout << e + 1 << " ";
    cout << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int64_t n;
    cin >> n;
    for(int64_t i = 0 ; i < n ; i ++){
        for(int64_t j = 0 ; j < n ; j++){
            cin >> m[i][j];
        }
    }
    for(int64_t k = 0 ; k < n ; k ++){
        for(int64_t i = 0 ; i < n ; i ++){
            for(int64_t j = 0 ; j < n ; j ++){
                if(m[i][k]+m[k][j]<m[i][j]){
                    m[i][j] = m[i][k]+m[k][j];
                    last[i][j] = k!=i ? k : j;
                }
            }
        }
    }
    for(int64_t i = 0 ; i < n ; i ++)
        if(m[i][i]<0){
            cout << "YES\n";
            //cout <<"i: " << i << m[i][i] << "last[0][0]: " << last[0][0] << " last[1][0]: " << last[1][0]  <<"\n";
            //return 0;
            restoreCycle(i);
            return 0;
        }
    cout << "NO\n";
    return 0;
}