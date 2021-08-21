#include <bits/stdc++.h>

using namespace std;

int matrix[108][108];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n ; 
    cin >> n ;
    vector<int> sources, sinks;
    for(int i = 1 ; i <= n ; i ++){
        int outN = 0 ; 
        for(int j = 1 ; j <= n ; j ++){
            cin >> matrix[i][j];
            outN += matrix[i][j];
        }
        if(!outN)
            sinks.push_back(i);
    }
    for(int i = 1 ; i <= n ; i ++){
        int inN = 0 ; 
        for(int j = 1 ; j <= n ; j ++){
            inN += matrix[j][i];
        }
        if(!inN)
            sources.push_back(i);
    }
    cout << sources.size() << " ";
    for(auto e = sources.begin(); e!=sources.end();e++)
        cout << *e << " ";
    cout << "\n" << sinks.size() << " ";
    for(auto e = sinks.begin(); e!=sinks.end();e++)
        cout << *e << " ";
    cout << "\n";
    return 0;
}