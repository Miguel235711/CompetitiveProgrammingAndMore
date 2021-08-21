#include<bits/stdc++.h>

#define MOD 1000000000

using namespace std;

int memo[108][4][3],n,movs[8][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2}};

bool prohibited(int r,int c){
    return r==3 && (c == 0 || c == 2);
}

bool inside(int r,int c){
    return r > -1 && r < 4 && c > -1 && c < 3 && !prohibited(r,c) ;
}

int f(int i,int r, int c){
    if(i==n)
        return 1;
    if(memo[i][r][c]!=-1)
        return memo[i][r][c];
    int ans = 0 ;
    for(int mov = 0 ; mov < 8 ; mov ++){
        int nR = r + movs[mov][0], nC = c + movs[mov][1];
        if(inside(nR,nC)){
            ans+=f(i+1,nR,nC);  
            ans%=MOD;
        }
    }
    return memo[i][r][c] = ans;
}

bool beginProhibited(int r, int c){
    return c == 1 && (r == 2 || r == 3);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ; 
    memset(memo,-1,sizeof(memo));
    int ans = 0;
    for(int i = 0 ; i < 4 ; i ++)
        for(int j = 0 ; j < 3 ; j ++)
            if(!prohibited(i,j)&&!beginProhibited(i,j)){
                ans+=f(1,i,j);
                ans%=MOD;
            }
    cout << ans << "\n";
    return 0;
}