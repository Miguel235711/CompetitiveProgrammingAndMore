#include<bits/stdc++.h>

using namespace std;

struct bumper{
    int val,cost;
    bumper(int val,int cost){
        this->val=val;
        this->cost=cost;
    }
    bumper(){
        this->val=this->cost=INT_MIN;
    }
};
int n,m,costWall,ans,p;
bumper grid[50][50];
int turnRight(int dir){
    return dir==0?3:dir-1;
}
int movs[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool isWall(int x,int y){
    return x==0||y==0||x==m-1||y==n-1;
}
int simulation(int x,int y,int dir,int life){
    int ans=0;
    while(--life>0){
        //move
        y+=movs[dir][0];
        x+=movs[dir][1];
        bool isW = isWall(x,y);
        if(isW||grid[y][x].val!=INT_MIN){
            if(isW)
                life-=costWall;
            else{
                ans+=grid[y][x].val;
                life-=grid[y][x].cost;
            }
            y-=movs[dir][0];
            x-=movs[dir][1];
            dir=turnRight(dir);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>m>>n>>costWall>>p;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            grid[i][j]=bumper();
    int x,y,dir,life,val,cost;
    while(p--){
        cin>>x>>y>>val>>cost;
        grid[y-1][x-1]=bumper(val,cost);
    }
    while(cin>>x>>y>>dir>>life){
        int subAns=simulation(x-1,y-1,dir,life);
        ans+=subAns;
        cout<<subAns<<"\n";
    }
    cout<<ans<<"\n";
    return 0;
}