#include<bits/stdc++.h>

#define lim 20

using namespace std;

int nextInt(int & i,const string & s){
    int x = 0 ; 
    for(;s[i]==' ';i++);
    for(;s[i]!=' ';i++)
        x=x*10+s[i]-'0';
    return x;
}
char visited[2][lim][lim];
int movs[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

bool inside(int x){
    return x>-1&&x<20;
}

bool isAlife(bool cur,int i , int j){
    return inside(i)&&inside(j)&&visited[cur][i][j]=='O';
}

int countAdj(bool cur,int i,int j){
    int counter = 0 ;
    for(int mov = 0 ; mov < 8 ; mov ++)
        if(isAlife(cur,i+movs[mov][0],j+movs[mov][1]))
            counter ++;
    return counter;
}

string asterisks = string(20,'*');

void simulate(int years){
    for(int y = 0 ; y < years; y ++){
        //print only O, not o
        for(int i = 0 ; i < lim ; i++ ){
            for(int j = 0 ; j < lim ; j++)
                cout << visited[y&1][i][j];
            cout << "\n";
        }
        cout << asterisks << "\n";
        //kill and born for next year
        for(int i = 0 ; i < lim ; i ++){
            for(int j = 0 ; j < lim ; j ++){
                int adj = countAdj(y&1,i,j);
                if(visited[y&1][i][j]=='O'&&(adj<2||adj>3)){
                    visited[(y+1)&1][i][j]=' ';//kill
                }else if(visited[y&1][i][j]==' '&&adj==3){
                    visited[(y+1)&1][i][j]='O';//born
                }else{
                    visited[(y+1)&1][i][j]=visited[y&1][i][j];//same
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    string line;
    cin >> t ;
    cin.ignore();
    cin.ignore();
    while(t--){
        cout << asterisks << "\n";
        memset(visited,' ',sizeof(visited));
        int years;
        cin >> years;
        cin.ignore();
        while(getline(cin,line)&&!line.empty()){
            int i = 0 ;
            line.push_back(' ');
            int r = nextInt(i,line)-1, c = nextInt(i,line)-1;
            visited[0][r][c]='O';
        }
        simulate(years);
        if(t)cout << "\n";
    }
    return 0;
}