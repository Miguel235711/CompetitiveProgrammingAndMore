#include<bits/stdc++.h>

using namespace std;

int difOutside[4]={1,1,-1,-1},difInside[4]={1,-1,1,-1},*begOutside,*begInside,N;
typedef vector<vector<int> > matrixType; 
vector<vector<vector<int> > >visitedGrids;
void toggle(int i,int j){
    if(!visitedGrids.empty())
        visitedGrids.push_back(visitedGrids.back());
    else
        visitedGrids.push_back(matrixType(N,vector<int>(N)));
    visitedGrids[visitedGrids.size()-1][i][j]=1-visitedGrids[visitedGrids.size()-1][i][j];
}
bool areEqual(const matrixType & gridNormal,const matrixType & gridEspecial,int mov){
    for(int outside=begOutside[mov],i=0;i<N;outside+=difOutside[mov],i++)
        for(int inside=begInside[mov],j=0;j<N;inside+=difInside[mov],j++){
            int one=outside,two=inside;
            if(mov==1||mov==2)
                swap(one,two);
            if(gridNormal[i][j]!=gridEspecial[one][two])
                return false;
        }
    return true;
}
bool loses(){
    int lim=visitedGrids.size()-1;
    for(int i=0;i<lim;i++)
        for(int mov=0;mov<4;mov++)
            if(areEqual(visitedGrids[i],visitedGrids[visitedGrids.size()-1],mov))
                return true;
    return false;
}
void init(){
    begOutside=new int[4]{0,0,N-1,N-1};
    begInside=new int[4]{0,N-1,0,N-1};
    visitedGrids.clear();
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>N,N){
        init();
        bool draw=true;
        int lim=N<<1,i,j;
        char com;
        for(int t=0;t<lim;t++){
            cin>>i>>j>>com;
            i--,j--;
            if(draw){
                toggle(i,j);
                if(loses()){
                    cout<<"Player "<<2-(t&1)<<" wins on move "<<t+1;
                    draw=false;
                }
            }
        }
        if(draw)
            cout<<"Draw";
        cout<<"\n";
    }
    return 0;
}