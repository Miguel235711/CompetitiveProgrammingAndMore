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
bool used[12][12];
int numberUsed=0;
void initialize(){
    memset(used,0,sizeof(used));
    numberUsed=0;
}
void visitCell(int i,int j){
    if(!used[i][j]){
        used[i][j]=true;
        numberUsed++;
    }
}
void visitAttacked(int i,int j,config movRow){
    int sz = sizeof(movs[movRow.movIndex])/sizeof(int**);
    for(int mov = 0 ; mov < sz; mov++){
        for(int iN = i+movs[movRow.movIndex][mov][0],jN=j+movs[movRow.movIndex][mov][1];grid[iN][jN]=='.';iN+=movs[movRow.movIndex][mov][0],jN+=movs[movRow.movIndex][mov][1]){
            visitCell(iN,jN);
            if(!movRow.isN)
                break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string line;
    while(getline(cin,line)){
        initialize();
        for(int i=2,j=2,index=0; index < line.size();index++){
            char c = line[index];
            if(c=='/'){
                j=2;
                i++;
            }else if(isdigit(c)){
                for(int t = c-'0';t>0;t--,j++){
                    grid[i][j]='.';
                }
            }else{
                grid[i][j++]=c;
            }
        }
        for(int i = 2 ; i < 10 ; i ++){
            for(int j = 2 ; j < 10 ; j++){
                if(grid[i][j]!='.'){
                    visitCell(i,j);
                    visitAttacked(i,j,getMovRow[grid[i][j]=='p'||grid[i][j]=='P'?grid[i][j]:tolower(grid[i][j])]);
                }
            }
        }
        cout << 8*8-numberUsed << "\n";
    }
    
    return 0;
}