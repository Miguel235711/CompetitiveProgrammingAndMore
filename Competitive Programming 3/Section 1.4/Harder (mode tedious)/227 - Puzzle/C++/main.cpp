#include<bits/stdc++.h>

using namespace std;

char grid[5][5];
int iE,jE;
string line;
map<char,vector<int> >getAdjacent={
    make_pair('L',vector<int>{0,-1}),
    make_pair('R',vector<int>{0,1}),
    make_pair('B',vector<int>{1,0}),
    make_pair('A',vector<int>{-1,0})
};
bool valid(int i,int j){
    return i>-1&&j>-1&&i<5&&j<5;
}
bool successfull(char command){
    auto it = getAdjacent.find(command);
    if(it==getAdjacent.end())
        return false;
    auto adjMov=it->second;
    auto newIE=iE+adjMov[0],newJE=jE+adjMov[1];
    if(!valid(newIE,newJE))
        return false;
    //make move
    grid[iE][jE]=grid[newIE][newJE];
    grid[newIE][newJE]=' ';
    iE=newIE,jE=newJE;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int cs=1;1;cs++){
        for(int i=0;i<5;i++){
            getline(cin,line);
            if(line[0]=='Z')
                return 0;
            for(int j=0;j<5;j++){
                grid[i][j]=line[j];
                if(grid[i][j]==' ')
                    iE=i,jE=j;
            }
        }
        cout<<(cs>1?"\n":"")<<"Puzzle #"<<cs<<":\n";
        auto possible=true,moreCommands=true;
        while(moreCommands){
            getline(cin,line);
            for(auto command:line){
                if(command=='0'){
                    moreCommands=false;
                    break;
                }else if(possible&&!successfull(command)){
                    possible=false;
                    cout<<"This puzzle has no final configuration."<<"\n";
                }
            }
        }
        if(possible)
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++)
                    cout<<(j>0?" ":"")<<grid[i][j];
                cout<<"\n";
            }
    }
    return 0;
}