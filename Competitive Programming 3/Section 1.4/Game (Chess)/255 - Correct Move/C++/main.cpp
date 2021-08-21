#include<bits/stdc++.h>

using namespace std;

vector<int> movs={1,-1,8,-8};
string mapToAns[] = {"Illegal state","Illegal move","Move not allowed","Continue","Stop"};
bool colMov(int a,int b){
    return a/8==b/8;
}
int getInc(int Q,int newQ){
    return (newQ-Q)%8==0 ? 8 : (colMov(Q,newQ)?1:0) ;
}

int validMov(int Q,int newQ,int K){
    if(Q>newQ)
        swap(Q,newQ);
    int inc = getInc(Q,newQ);
    if (!inc)
        return false;
    for(;Q<=newQ;Q+=inc)
        if(Q==K)
            return false;
    return true;
}
bool reachesPlaceOfOther(int newQ,int K){
    return newQ==K-8||newQ==K+8||(colMov(K,K+1)&&newQ==K+1)||(colMov(K,K-1)&&newQ==K-1);
}
bool insideMap(int p){
    return -1<p&&p<64;
}
bool validKing(int K,vector<int>Qpositions){
    for(int mov:movs)
        if(insideMap(K+mov)){
            bool possible = true;
            for (int Qposition:Qpositions)
                if(K+mov==Qposition){
                    possible=false;
                    break;
                }
            if(possible)
                return true;
        }
    return false;
}
vector<int> getQPositions(int p){
    vector<int>ans={p};
    for (int mov:movs)
        for(int newP = p + mov; (abs(mov)==8 && insideMap(newP))||(abs(mov)==1&&colMov(newP,p));newP+=mov)
            ans.push_back(newP);
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int K,Q,newQ;
    while(cin>>K>>Q>>newQ){
        int ans = 4;
        if(K==Q)
            ans = 0;
        else if(Q==newQ||!validMov(Q,newQ,K))
            ans = 1;
        else if(reachesPlaceOfOther(newQ,K))
            ans = 2;
        else if(validKing(K,getQPositions(newQ)))
            ans = 3;
        cout << mapToAns[ans] << "\n";
    }
    return 0;
}