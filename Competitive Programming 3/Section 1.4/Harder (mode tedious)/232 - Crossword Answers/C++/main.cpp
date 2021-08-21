#include<bits/stdc++.h>

using namespace std;

int movs[2][2]={{0,1},{1,0}},r,c,numbers[11][11];
string names[2]={"Across","Down"};
char grid[12][12];

void printAns(int i,int j,int *mov,int number){
    cout<<" "<<(number<10?" ":"")<<number<<'.';
    for(;grid[i][j]!='*';i+=mov[0],j+=mov[1])
        cout<<grid[i][j];
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int cs=1;cin>>r&&r;cs++){
        cin>>c;
        int num=0;
        cout<<(cs>1?"\n":"")<<"puzzle #"<<cs<<":\n";
        memset(grid,'*',sizeof(grid));
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++){
                cin>>grid[i][j];
                if(grid[i][j]!='*'&&(grid[i-1][j]=='*'||grid[i][j-1]=='*'))
                    numbers[i][j]=++num;
            }
        for(int mov=0;mov<2;mov++){
            cout<<names[mov]<<"\n";
            for(int i=1;i<=r;i++)
                for(int j=1;j<=c;j++)
                    if(grid[i][j]!='*'&&grid[i-movs[mov][0]][j-movs[mov][1]]=='*')
                        printAns(i,j,movs[mov],numbers[i][j]);
        }
    }
    return 0;
}