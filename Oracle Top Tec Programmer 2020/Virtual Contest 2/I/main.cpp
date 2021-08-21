#include<bits/stdc++.h>
#define limit 502

using namespace std ; 

int r,c;

char matrix[limit][limit];
int movs[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

bool possible(){
    for(int i = 1 ; i <= r ; i ++ ){
        for(int j = 1 ; j <= c ; j ++){
            if(matrix[i][j]=='S'){
                for(int mov = 0 ; mov < 4 ; mov ++ ){
                    char valueAdj = matrix[i+movs[mov][0]][j+movs[mov][1]];
                    if(valueAdj=='W'){
                        return false;
                    }else if(valueAdj!='S'){
                        matrix[i+movs[mov][0]][j+movs[mov][1]] = 'D';
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> r >> c ;
    for(int i = 1 ; i <= r ; i ++ ){
        for(int j = 1 ; j <= c ; j ++){
            cin >> matrix[i][j];
            if(matrix[i][j]=='.'){
                matrix[i][j]='\0';
            }
        }
    }
    if(possible()){
        cout << "Yes\n";
        for(int i = 1 ; i <= r ; i ++ ){
            for(int j = 1 ; j <= c ; j ++){
                cout << (matrix[i][j]=='\0'?'.':matrix[i][j]);
            }
            cout << "\n";
        }
    }else{
        cout << "No\n";
    }
    return 0;
}