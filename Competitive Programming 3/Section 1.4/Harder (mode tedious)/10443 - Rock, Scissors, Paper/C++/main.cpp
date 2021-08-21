#include<bits/stdc++.h>

using namespace std;


char matrix[2][100][100];
int movs[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
set<pair<char,char> >wins={
    make_pair('R','S'),
    make_pair('S','P'),
    make_pair('P','R')
};
int r,c;
int insideLimit(int x,int upperLimit){
    return -1<x&&x<upperLimit;
}
int insideLimits(int i,int j){
    return insideLimit(i,r)&&insideLimit(j,c);
}

bool kills(char a,char b){
    return wins.find(make_pair(a,b))!=wins.end();
}
auto szMatrix= sizeof(matrix[0]);
void simulation(int t){
    for(int time = 1 ; time <= t ; time++){
        memcpy(matrix[time&1],matrix[(time-1)&1],szMatrix);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                for(int mov = 0; mov < 4 ; mov ++){
                    int iS= i +movs[mov][0], jS=j+movs[mov][1];
                    if(insideLimits(iS,jS)&&kills(matrix[(time-1)&1][i][j],matrix[(time-1)&1][iS][jS]))
                        matrix[time&1][iS][jS]=matrix[(time-1)&1][i][j];
                }
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cout << matrix[t&1][i][j];
        cout << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n;
    cin >> t;
    for(int cas = 0 ; cas < t ; cas ++){
        cin >> r >> c >> n;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin >> matrix[0][i][j];
        if(cas)
            cout << "\n";
        simulation(n);
    }
    return 0;
}