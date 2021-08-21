#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > movs={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
char grid[8][8];
bool inLimit(int i,int j){
    return i>-1&&j>-1&&i<8&&j<8;
}
struct brack{
    vector<int> mov;
    int times;
    brack(){}
    brack(vector<int>mov,int times){
        this->mov=mov;
        this->times=times;
    }
};
int calcDif(int i1,int i2,int j1,int j2){
    return max(abs(j2-j1),abs(i2-i1));
}
char nextPlayer(char currentPlayer){
    return currentPlayer=='B'?'W':'B';
}
vector<int> possibleLimitCoordinate(vector<int>mov, int i,int j, char currentPlayer){
    //we are sure that i,j is empty when calling this function
    int iN=i+mov[0],jN=j+mov[1];
    char nextP=nextPlayer(currentPlayer);
    while(inLimit(iN,jN)&&grid[iN][jN]==nextP){
        iN+=mov[0],jN+=mov[1];
    }
    if(inLimit(iN,jN)&&grid[iN][jN]==currentPlayer&&calcDif(i,iN,j,jN)>1)
        return {iN,jN};
    return {};
}
void listPossibleMoves(char currentPlayer){
    bool atLeastOne=false;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(grid[i][j]=='-')
                for(auto mov: movs)
                    if(!possibleLimitCoordinate(mov,i,j,currentPlayer).empty()){
                        cout<<(atLeastOne?" ":"")<<"("<<i+1<<","<<j+1<<")";
                        atLeastOne=true;
                        break;
                    }
    cout<<(atLeastOne?"":"No legal move.")<<"\n";
}
vector<brack> getBracketed(char currentPlayer,int i,int j){
    vector<brack> bracketed;
    for(auto mov:movs){
        auto limitCoord=possibleLimitCoordinate(mov,i,j,currentPlayer);
        if(!limitCoord.empty())
            bracketed.push_back(brack(mov,calcDif(i,limitCoord[0],j,limitCoord[1])-1));
    }
    return bracketed;
}
void makeMoveAndPrintPieceNumbers(int i,int j,char currentPlayer,vector<brack>bracketed){
    grid[i][j]=currentPlayer;
    //bracketed required
    for(auto bracket:bracketed){
        int subI=i,subJ=j;
        for(int t=0;t<bracket.times;t++){
            subI+=bracket.mov[0],subJ+=bracket.mov[1];
            grid[subI][subJ]=currentPlayer;
        }
    }
    //count
    int black=0,white=0;
    for(int iG=0;iG<8;iG++)
        for(int jG=0;jG<8;jG++)
            if(grid[iG][jG]=='W')
                white++;
            else if(grid[iG][jG]=='B')
                black++;
    cout<<"Black - "<<(black<10?" ":"")<<black<<" White - "<<(white<10?" ":"")<<white<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    for(int cs=0;cs<t;cs++){
        if(cs>0)
            cout<<"\n";
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                cin>>grid[i][j];
        char currentPlayer;
        cin>>currentPlayer;
        string command;
        cin.ignore();
        while(getline(cin,command),command[0]!='Q'){
            if(command[0]=='L')
                listPossibleMoves(currentPlayer);
            else if(command[0]=='M'){
                int i=command[1]-'0'-1,j=command[2]-'0'-1;
                vector<brack>bracketed=getBracketed(currentPlayer,i,j);
                if(bracketed.empty()){
                    currentPlayer=nextPlayer(currentPlayer);
                    bracketed=getBracketed(currentPlayer,i,j);
                }
                makeMoveAndPrintPieceNumbers(i,j,currentPlayer,bracketed);
                currentPlayer=nextPlayer(currentPlayer);
            }
        }
        //print grid
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++)
                cout<<grid[i][j];
            cout<<"\n";
        }
    }
    return 0;
}