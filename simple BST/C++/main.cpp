#include<bits/stdc++.h>

using namespace std;

struct node{
    int k,v,l,r;
    node(int k,int v,int l,int r){
        this->k=k;
        this->v=v;
        this->l=l;
        this->r=r;
    }
    node(){}
}nodes[1000008];
int lim = -1;
void insert(int k, int v){
    nodes[++lim] = node(k,v,-1,-1);
    if(lim){
        auto index = 0;
        for(;;){
            int & targetSide = k < nodes[index].k ? nodes[index].l : nodes[index].r;
            if(targetSide==-1){
                targetSide = lim;
                return;
            }else
                index = targetSide;
        }
    }
}
int find(int k){///returns v
    int index = 0;
    while(index!=-1){
        if(nodes[index].k==k)
            return nodes[index].v;
        index = k < nodes[index].k ? nodes[index].l : nodes[index].r;
    }
    return INT_MAX;
}

void preorder(int index){
    if(index==-1)
        return;
    cout << nodes[index].k << " ";
    preorder(nodes[index].l),preorder(nodes[index].r);
}
void inorder(int index){
    if(index==-1)
        return;
    inorder(nodes[index].l);
    cout << nodes[index].k << " ";
    inorder(nodes[index].r);
}
void posorder(int index){
    if(index==-1)
        return;
    posorder(nodes[index].l),posorder(nodes[index].r);
    cout << nodes[index].k << " ";
}
void preorder(){
    cout << "Preorder:\n";
    preorder(0);
    cout << "\n";
}
void inorder(){
    cout << "Inorder:\n";
    inorder(0);
    cout << "\n";
}   
void posorder(){
    cout << "Posorder:\n";
    posorder(0);
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,xi; 
    cin >> n ; 
    vector<int> inputSequence;
    for(int i = 0 ; i < n ; i ++){
        cin >> xi;
        inputSequence.push_back(xi);
        insert(xi,xi);
    }
    for(int x: inputSequence){
        cout << "find(" << x << ") = " << find(x) << "\n"; 
    }
    for(int i = 0 ; i <= lim ; i ++)
        cout 
        << nodes[i].k << " " 
        << nodes[i].l << " " 
        << nodes[i].r << " " 
        << nodes[i].v << "\n";
    preorder();
    inorder();
    posorder();
    return 0;
}