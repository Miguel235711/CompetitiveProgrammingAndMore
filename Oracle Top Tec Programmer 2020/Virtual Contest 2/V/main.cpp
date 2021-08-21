#include<bits/stdc++.h>
#define globalT 4

using namespace std ; 

int n,m,tGlobal;

char grid[12][12];

double memo[9][9][200];

int movs[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//south,east,north,west
double P[4];
char currentAvailable=1;

void changeCord(int &i,int &j,int mov){
    if(grid[i+movs[mov][0]][j+movs[mov][1]]){
        i+=movs[mov][0],j+=movs[mov][1];
    }
}

double f(int i,int j,int t){
    if(grid[i][j]=='*'){
        return 0 ; 
    }
    if(!t){
        return 0 ; 
    }
    if(memo[i][j][t]!=-1){
        return memo[i][j][t];
    }
    double ans = 0 ; 
    for(int mov = 0 ; mov < 4 ; mov ++){
        int iNew = i , jNew = j ; 
        changeCord(iNew,jNew,mov);
        ans += (f(iNew,jNew,t-1)+1)*P[mov];
    }
    return memo[i][j][t]=ans; 
}

void initializeMemo(){
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= m ; j ++){
            for(int tI = 1 ; tI <= 4 ; tI ++){
                memo[i][j][tI]=-1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> P[2] >> P[1]>> P[0] >> P[3] ; 
    int initialI , initialJ ; 
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= m ; j++){
            cin >> grid[i][j];
            if(grid[i][j]=='#'){
                //blocked
                grid[i][j]='\0';
            }else if(grid[i][j]=='@'){
                //initial pos
                initialI = i ;
                initialJ = j ; 
            }
        }
    }
    initializeMemo();
    cout << f(initialI,initialJ,globalT) << "\n";
    //for(int i = 1 ; i <= tGlobal ; i ++ )
        //cout << fixed << setprecision(12) << f(initialI,initialJ,0,i) << "\n";
    //dp();
    //cout << fixed << setprecision(12) << memo[initialI][initialJ][0][tGlobal&1] << "\n";
    /*for(int t = 1 ; t <= tGlobal ; t ++){
        cout << "current t: " << t << "|\n";
        for(int i = 1 ; i <= n ; i ++ ){
            for(int j = 1 ; j <= m ; j ++){
                cout << fixed << setprecision(12) << memo[i][j][0][t] << " ";
            }
            cout << "\n";
        }
        cout << "-----------------------\n";
    }*/
    return 0;
}