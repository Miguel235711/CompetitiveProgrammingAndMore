#include<bits/stdc++.h>
#define maxN 100008
#define maxLogN 17

using namespace std;

int parent[maxN][18];
int age[maxN],N,M,Ai,Bi;
vector<int> minAgesAllowed[maxN];

void precalcLCA(){
    for(int l = 1 ; l <= maxLogN ; l++){
        for(int i = 1 ; i <= N ; i ++)
            parent[i][l]=parent[parent[i][l-1]][l-1];
    }
}
vector<int> graph[maxN];

///BIT
int BIT[maxN];

int magic(int x ) {
    return x&-x;
}

int query(int pos ) {
    int ans = 0 ;
    while(pos>=1){
        ans+=BIT[pos];
        pos-=magic(pos);
    }
    return ans;
}

/*int sum(int i , int j ) {
    return query(j)-query(i-1);
}*/
void modify(int pos, int x){
    while(pos <= maxN){
        BIT[pos]+=x;
        pos+=magic(pos);
    }
}

///tree transverse

int ans[maxN];

void f(int node,int parent){
    //add minAgesAllowed[node] to BIT
    for(int minAge: minAgesAllowed[node]){
        modify(minAge,1);
    }
    ans[node] = query(age[node]);
    for(int child: graph[node]){
        if(child!=parent)
            f(child,node);
    }
    //remove minAgesAllowed[node] from BIT
    for(int minAge: minAgesAllowed[node]){
        modify(minAge,-1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i ++){
        cin >> Ai >> Bi;
        graph[Bi].push_back(i);
        graph[i].push_back(Bi);
        parent[i][0]=Bi;
        age[i]=Ai;
    }
    precalcLCA();
    int O,L,R;
    //cout << "inmediate parent\n";
    /*for(int i = 1 ; i <= N ; i ++){
        cout << parent[i][0] << "\n";
    }*/
    while(M--){
        cin >> O >> L >> R;
        ///organizer and range
        //up while it age is less than R
        int node = O;
        for(int l = maxLogN ; l > -1 ; l--){
            int candidateP = parent[node][l];
            //cout << "candidateP: " << candidateP << "\n";
            if(age[candidateP]<=R)
                node = candidateP;
        } 
        //cout << "node chosen: " << node << "\n";
        minAgesAllowed[node].push_back(L);
    }
    ///transverse tree
    f(1,1);
    for(int i = 1 ; i <= N ; i ++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}