#include<bits/stdc++.h>

using namespace std;

int dishes[2][42],dna[10];
char toChar[4]={' ','.','x','W'};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    for(int cs = 0 ; cs < t ; cs++){
        if(cs)
            cout << "\n";
        memset(dishes,0,sizeof(dishes));
        dishes[0][20]=1;
        for(int i = 0 ; i < 10 ; i ++)
            cin >> dna[i];
        for(int y = 0 ; y < 50 ; y++){
            bool yA = y&1;
            //print
            for(int i = 1; i < 41 ; i ++)
                cout << toChar[dishes[yA][i]];
            cout << "\n";
            //change
            for(int i = 1 ; i < 41 ; i ++)
                dishes[(y+1)&1][i]=dna[dishes[yA][i-1]+dishes[yA][i]+dishes[yA][i+1]];
        }
    }
    return 0;
}