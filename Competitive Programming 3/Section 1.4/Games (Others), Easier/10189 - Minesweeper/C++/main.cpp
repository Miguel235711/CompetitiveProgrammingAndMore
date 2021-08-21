#include<bits/stdc++.h>

using namespace std;

int movs[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}},n,m;
char field[102][102];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int cs=1;cin>>n>>m&&n;cs++){
        if(cs>1)
            cout<<"\n";
        cout<<"Field #"<<cs<<":\n";
        memset(field,'0',sizeof(field));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>field[i][j];
                field[i][j]=field[i][j]=='.'?'0':'1';
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char ans='*';
                if(field[i][j]!='1'){
                    ans='0';
                    for(int mov=0;mov<8;mov++)
                        ans+=field[i+movs[mov][0]][j+movs[mov][1]]-'0';
                }
                cout<<ans;
            }
            cout<<"\n";
        }
    }
    return 0;
}