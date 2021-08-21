#include <bits/stdc++.h>
#define maxL  300008

using namespace std;

struct node{
    int l,r,x;
};

int n,ans[maxL];
node seg[maxL*4];
  

void build(int index,int l,int r){
    seg[index].l=l,seg[index].r=r;
    if(l==r)
        seg[index].x = l;
    else
    {
        int mid = (l+r)>>1,newIndex = index<<1;
        build(newIndex,l,mid),build(newIndex+1,mid+1,r);
        seg[index].x=max(seg[newIndex].x,seg[newIndex+1].x);
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
    seg[index].x = max(seg[index<<1].x,seg[(index<<1)+1].x);
}

int query(int index,int l,int r){
    if(seg[index].l>r || seg[index].r<l)
        return 0;
    if(l<=seg[index].l&&seg[index].r<=r)
        return seg[index].x;
    return max(query(index<<1,l,r),query((index<<1)+1,l,r));
}

int main(){
    int m,l,r,x;
    cin >> n >> m ;
    build(1,1,n);
    while(m--){
        cin >> l >> r >> x;
        for(int qAns = query(1,l,r);qAns;qAns = query(1,l,r))
            update(1,qAns,0),ans[qAns] = x;
        ans[x]=0;
        update(1,x,x);
    }
    for(int i = 1 ; i <= n ; i ++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}