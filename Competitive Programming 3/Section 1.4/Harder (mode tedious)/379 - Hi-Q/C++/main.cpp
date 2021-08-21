#include<bits/stdc++.h>

using namespace std;

int grid[7][7]={
    {0,0,1,2,3,0,0},
    {0,0,4,5,6,0,0},
    {7,8,9,10,11,12,13},
    {14,15,16,17,18,19,20},
    {21,22,23,24,25,26,27},
    {0,0,28,29,30,0,0},
    {0,0,31,32,33,0,0}
},
movs[4][2]={{1,0},{0,1},{-1,0},{0,-1}},
n;
bool vis[7][7];
struct coord{
    int i,j;
    coord(int i,int j){
        this->i=i;
        this->j=j;
    }
    coord(){}
};
coord getCoord(int x){
    int i=(x-28)/3+5,j=(x-1)%3+2;
    if(7<=x&&x<=27)
        i=x/7+1,j=x%7;
    else if(1<=x&&x<=6)
        i=(x-1)/3,j=(x-1)%3+2;
    return coord(i,j);
}
bool inside(int i,int j){
    return i>-1&&j>-1&&i<7&&j<7&&grid[i][j]!=0;
}
bool visited(int i,int j){
    return inside(i,j)&&vis[i][j];
}
bool free(int i, int j){
    return inside(i,j)&&!vis[i][j];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout<<"HI Q OUTPUT\n";
    cin>>n;
    while(n--){
        int x,sum=0;
        memset(vis,0,sizeof(vis));
        while(cin>>x&&x){
            coord c=getCoord(x);
            sum+=x;
            vis[c.i][c.j]=true;
        }
        //try to make k movements
        int origX,maxTarget,intermediary=0;
        do{
            maxTarget=-1;
            for(int i=0;i<7;i++)
                for(int j=0;j<7;j++)
                    if(vis[i][j])
                        //for every movement
                        for(int mov=0;mov<4;mov++)
                            if(visited(i+movs[mov][0],j+movs[mov][1])&&free(i+movs[mov][0]*2,j+movs[mov][1]*2)){
                                int target=grid[i+movs[mov][0]*2][j+movs[mov][1]*2];
                                if(target>maxTarget||(target==maxTarget&&grid[i][j]>origX)){
                                    origX=grid[i][j];
                                    maxTarget=target;
                                    intermediary=grid[i+movs[mov][0]][j+movs[mov][1]];
                                }
                            }
            if(maxTarget!=-1){
                coord targetC=getCoord(maxTarget),origC=getCoord(origX),interC=getCoord(intermediary);
                vis[targetC.i][targetC.j]=true;
                vis[origC.i][origC.j]=vis[interC.i][interC.j]=false;
                sum+=-origX-intermediary+maxTarget;
            }
        }while(maxTarget!=-1);//maxTarget should be -1 when movement found
        cout<<sum<<"\n";
    }
    cout<<"END OF OUTPUT\n";
    return 0;
}