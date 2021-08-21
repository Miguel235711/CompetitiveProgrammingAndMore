#include<bits/stdc++.h>

using namespace std;

int movs[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}},t,n;
char grid[12][12],el;
char getAns(char c,bool showMines){
    if(c=='*')
        return showMines?'*':'.';
    return c;
}
int convert(char c){
    return c=='*';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    for(int cs=0;cs<t;cs++){
        if(cs>0)
            cout << "\n";
        memset(grid,'.',sizeof(grid));
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>grid[i][j];
        bool showMines=false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>el;
                if(el=='x')//touched
                    if(grid[i][j]=='*')//bomb
                        showMines=true;
                    else{ //not bomb
                        grid[i][j]='0';
                        for(int mov=0;mov<8;mov++)
                            grid[i][j]+=convert(grid[i+movs[mov][0]][j+movs[mov][1]]);
                    }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cout<<getAns(grid[i][j],showMines);
            cout<<"\n";
        }
    }
    return 0;
}