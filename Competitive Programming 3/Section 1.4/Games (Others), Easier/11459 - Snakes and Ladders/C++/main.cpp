#include<bits/stdc++.h>

using namespace std;

int t,a,b,c,goDif[100];

void printAns(int * players){
    for(int i=0;i<a;i++)
        cout<<"Position of player "<<i+1<<" is " <<players[i]+1<<".\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        int players[a],orig,dest,val;
        memset(players,0,sizeof(players));
        memset(goDif,0,sizeof(goDif));
        for(int i=0;i<b;i++){
            cin>>orig>>dest;
            goDif[orig-1]=dest-orig;   
        }
        bool won=false;
        for(int i=0,player=0;i<c;i++){
            cin>>val;
            if(!won){
                players[player]=min(players[player]+val,99);
                players[player]+=goDif[players[player]];
                if(players[player]==99){//print answer
                    won=true;
                    printAns(players);
                }
                player=(player+1)%a;
            }
        }
        if(!won)
            printAns(players);
    }
    return 0;
}