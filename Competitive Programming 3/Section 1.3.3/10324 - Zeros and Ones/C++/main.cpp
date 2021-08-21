#include<bits/stdc++.h>

using namespace std;

int acum[1000002];
string line;

bool same(int i,int j){
    if(i>j)
        swap(i,j);
    //i<=j
    int rangeSum = acum[j+1]-acum[i];
    return rangeSum == 0 || rangeSum == j - i + 1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int cs=1;cin>>line;cs++){
        for(int i = 0 ; i < line.size(); i ++){
            acum[i+1]=acum[i]+line[i]-'0';
        }
        cout << "Case " << cs << ":\n";
        int n;
        cin >> n ;
        while(n--){
            int i,j;
            cin >> i >> j;
            cout << (same(i,j)?"Yes":"No") << "\n";
        }
    }
    return 0;
}