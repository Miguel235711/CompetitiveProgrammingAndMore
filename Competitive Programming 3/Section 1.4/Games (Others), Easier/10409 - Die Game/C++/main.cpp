#include<bits/stdc++.h>

using namespace std;

int aux[4],n;
map<string,pair<int,int> > mapMov={
    make_pair("south",make_pair(0,-1)),
    make_pair("north",make_pair(0,1)),
    make_pair("east",make_pair(1,-1)),
    make_pair("west",make_pair(1,1))
};
int minusOne(int i){
    if(i==0)
        return 3;
    return i-1;
}
int plusOne(int i){
    return (i+1)%4;
}
int One(int i,int dif){
    if(dif==1)
        return plusOne(i);
    return minusOne(i);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>n,n){
        int groups[2][4]={{6,2,1,5},{6,3,1,4}};
        while(n--){
            string line;
            cin>>line;
            auto com = mapMov.find(line)->second;
            for(int i=0;i<4;i++)
                aux[i]=groups[com.first][One(i,com.second)];
            copy(aux,aux+4,groups[com.first]);
            groups[1-com.first][0]=groups[com.first][0];
            groups[1-com.first][2]=groups[com.first][2];
        }
        cout<<groups[0][2]<<"\n";
    }
    return 0;
}