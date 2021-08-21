#include <bits/stdc++.h>
#define maxL  131080

using namespace std;

struct node{
    int l,r,x;
};

int arr[maxL],n;
node seg[maxL*4];

int f(int index){
    return (int)log2(seg[index].r-seg[index].l+1)&1?seg[index<<1].x | seg[(index<<1)+1].x : seg[index<<1].x ^ seg[(index<<1)+1].x;
}   

void build(int index,int l,int r){
    seg[index].l=l,seg[index].r=r;
    if(l==r)
        seg[index].x = arr[l];
    else
    {
        int mid = (l+r)>>1,newIndex = index<<1;
        build(newIndex,l,mid),build(newIndex+1,mid+1,r);
        seg[index].x=f(index);
    }
}

void update(int index,int i, int x){
    if(seg[index].l==seg[index].r){
        seg[index].x = x;
        return;
    }
    if(seg[index<<1].r<i)
        update((index<<1)+1,i,x);
    else
        update(index<<1,i,x);
    seg[index].x = f(index);
}

int main(){
    int m,power;
    cin >> power >> m ; 
    n  = 1 << power ;
    for(int i = 1; i <= n ; i ++)
        cin >> arr[i];
    build(1,1,n);
    int p,b; 
    while(m--){
        cin >> p >> b;
        update(1,p,b);
        cout << seg[1].x << "\n";
    }
    return 0;
}