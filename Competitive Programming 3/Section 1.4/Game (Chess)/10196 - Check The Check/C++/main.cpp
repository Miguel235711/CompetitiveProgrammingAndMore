#include<bits/stdc++.h>

using namespace std;

char grid[12][12];
int movs[][8][2]={
    {{1,-1},{1,1}},//black pawn (1)
    {{-1,-1},{-1,1}},//white pawn (1)
    {{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}}, // knight (1)
    {{1,1},{-1,-1},{-1,1},{1,-1}},//bishop (1..n)
    {{1,0},{-1,0},{0,1},{0,-1}}, // rook (1..n)
    {{1,1},{-1,-1},{-1,1},{1,-1},{1,0},{-1,0},{0,1},{0,-1}}//queen or king (special case [1..n and 1])
};
struct config{
    int movIndex;
    bool isN;
    config(int movIndex,bool isN){
        this->movIndex=movIndex;
        this->isN=isN;
    }
    config(){}
};
map<char,config> getMovRow = {
    make_pair('p',config(0,false)),
    make_pair('P',config(1,false)),
    make_pair('n',config(2,false)),
    make_pair('b',config(3,true)),
    make_pair('r',config(4,true)),
    make_pair('q',config(5,true)),
    make_pair('k',config(5,false))
};
bool attacks(int i,int j,config conf,char objective){
    int sz = sizeof(movs[conf.movIndex])/sizeof(int**);
    for(int mov = 0 ; mov < sz; mov++){
        int iN=i,jN=j;
        for(iN+=movs[conf.movIndex][mov][0],jN+=movs[conf.movIndex][mov][1];grid[iN][jN]=='.';iN+=movs[conf.movIndex][mov][0],jN+=movs[conf.movIndex][mov][1]){
            if(!conf.isN)
                break;
        }
        if(grid[iN][jN]==objective)
            return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int cs=1;1;cs++){
        bool differentFromPoint = false;
        for(int i = 2 ; i <= 9 ; i ++){
            for(int j = 2 ; j <= 9 ; j ++){
                cin >> grid[i][j];
                if(grid[i][j]!='.')
                    differentFromPoint=true;
            }
        }
        if(!differentFromPoint)
            return 0;
        string ans = "no king is in check.";
        for(int i = 2 ; i <= 9; i++){
            for(int j = 2 ; j <= 9 ; j ++){
                if(grid[i][j]!='.'){
                    char objective = islower(grid[i][j])?'K':'k';
                    char piece = grid[i][j]!='p' && grid[i][j]!='P' ? tolower(grid[i][j]) :grid[i][j];
                    if(attacks(i,j,getMovRow[piece],objective)){
                        ans = string(objective=='K'?"white":"black")+" king is in check.";
                        goto after;
                    }
                }
            }
        }
        after:
        cout << "Game #" << cs << ": " << ans << "\n";
    }
    return 0;
}