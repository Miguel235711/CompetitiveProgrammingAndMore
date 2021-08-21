#include<bits/stdc++.h>

using namespace std;

int matrix[10][40],cellsInColumn[40],occuppiedCells,movs[4][2]={{1,0},{0,1},{-1,0},{0,-1}},visit[10][40],color=0,N,M;

typedef pair<int,int> p;

bool isValid(int i,int j){
    return i>-1&&j>-1&&i<M&&j<N;
}
void getAdjacentCoordinates(int i,int j,int val,vector<p>&coords){
    for(int mov=0;mov<4;mov++){
        int iN=i+movs[mov][0],jN=j+movs[mov][1];
        if(isValid(iN,jN)&&matrix[iN][jN]==val&&visit[iN][jN]!=color){
            coords.push_back(make_pair(iN,jN));
            visit[iN][jN]=color;
            getAdjacentCoordinates(iN,jN,val,coords);
        }
    }
}
void copyColumn(int j1,int j2){
    for(int i=0;i<M;i++)
        matrix[i][j1]=matrix[i][j2];
}
void myFill(int j,int val){
    for(int i=0;i<M;i++)
        matrix[i][j]=val;
}
void fixPositions(){
    //fix each column
    for(int j=0;j<N;j++){
        int firstMinusOne=-1;
        if(cellsInColumn[j])
            for(int i=0;i<M;i++)
                if(matrix[i][j]==-1&&firstMinusOne==-1)
                    firstMinusOne=i;
                else if(matrix[i][j]!=-1&&firstMinusOne!=-1){
                    //splice
                    for(;i<M&&matrix[i][j]!=-1;i++){
                        matrix[firstMinusOne++][j]=matrix[i][j];
                        matrix[i][j]=-1;
                    }
                }
    }
    //fix all
    int firstMinusOne=-1;
    for(int j=0;j<N;j++)
        if(!cellsInColumn[j]&&firstMinusOne==-1)
            firstMinusOne=j;
        else if(cellsInColumn[j]&&firstMinusOne!=-1)
            //splice
            for(;j<N&&cellsInColumn[j];j++){
                //cout<<"J: -> " <<j <<"\n";
                copyColumn(firstMinusOne,j);
                myFill(j,-1);
                cellsInColumn[firstMinusOne]=cellsInColumn[j];
                cellsInColumn[j]=0;
                firstMinusOne++;
            }    
}  
void processCommand(int i,int j){
    if(isValid(i,j)&&matrix[i][j]!=-1){
        //process
        vector<p>coords{make_pair(i,j)};
        visit[i][j]=++color;
        getAdjacentCoordinates(i,j,matrix[i][j],coords);
        if(coords.size()>1){
            //valid group to remove
            for(auto coord: coords){
                matrix[coord.first][coord.second]=-1;
                cellsInColumn[coord.second]--;
                occuppiedCells--;
            }
            fixPositions();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int cs=0;cin>>M>>N&&M&&N;cs++){
        if(cs>0)
            cout<<"\n";
        occuppiedCells=N*M;
        fill(cellsInColumn,cellsInColumn+N,M);
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
                cin>>matrix[i][j];
        int iC,jC;
        while(cin>>iC>>jC,iC){
            if(occuppiedCells)
                processCommand(iC-1,jC-1);
        }
        cout<<"Grid "<<cs+1<<".\n";
        if(occuppiedCells){
            for(int i=M-1;i>-1;i--){
                cout<<"    ";
                for(int j=0;j<N;j++)
                    cout<<(j>0?" ":"")<<(matrix[i][j]==-1?" ":to_string(matrix[i][j]));
                cout<<"\n";
            }
        }else
            cout << "    Game Won\n";
    }
    return 0;
}