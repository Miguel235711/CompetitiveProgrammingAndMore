#include<bits/stdc++.h>

using namespace std;

int n,m,maxAns=0;
/*bool isQueen;
vector<pair<int,int> >pieces;
vector<pair<int,int> > movs[2] = {
{
    make_pair(0,1),make_pair(1,0),make_pair(-1,0),make_pair(0,-1),make_pair(1,1),make_pair(-1,-1),make_pair(1,-1),make_pair(-1,1)
},
{
    make_pair(2,1),make_pair(1,2),make_pair(-2,1),make_pair(2,-1),make_pair(-2,-1),make_pair(-1,2),make_pair(1,-2),make_pair(-1,-2)
}
};

bool inside(int i,int j){
    return -1<i&&i<m&&-1<j&&j<n;
}

bool possible(int i,int j, int isQueen){
    for(auto piece: pieces){
        for(auto mov:movs[!isQueen]){
            pair<int,int> p = make_pair(piece.first+mov.first,piece.second+mov.second);
            while(inside(p.first,p.second)){
                if(i==p.first&&j==p.second)
                    return false;
                if(!isQueen)
                    break;
                p.first+=mov.first,p.second+=mov.second;
            }
        }
    }
    return true;
}

void f(int i,int j){
    //cout << "i: " << i << "j: " << j << "\n";
    if(i+1==m&&j==n){
        maxAns=max(maxAns,(int)pieces.size());
    }else if(j==n){
        f(i+1,0);
    }else{
        //try put or not put
        if(possible(i,j,isQueen)){
            pieces.push_back(make_pair(i,j));
            f(i,j+1);
            pieces.pop_back();
        }
        f(i,j+1);
    }
}*/

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    char type;
    int t;
    cin >> t ;
    while(t--){
        cin >> type >> m >> n ; 
        if(type=='r'){
            maxAns = min(m,n);
        }else if(type=='k'){
            //f(0,0);
            if(n==1||m==1){
                maxAns = max(n,m);
            }else if (n==2 || m ==2){
                int l = max(n,m);
                int localAns = 0;
                localAns = (l+1)/4;
                localAns*=2;
                if(l%4==1 || l%4==2){
                    localAns += l%4;
                }
                maxAns = localAns*2;
            }else{
                maxAns = ((n*m)+1)/2;
            }
        }else if(type=='Q'){
            maxAns = m==n&&(n==2||m==3) ? n-1 : min(m,n);
            //f(0,0);
        }else{
            maxAns = ceil((float)m/2)*ceil((float)n/2);
        }
        cout << maxAns << "\n";
    }
    return 0;
}