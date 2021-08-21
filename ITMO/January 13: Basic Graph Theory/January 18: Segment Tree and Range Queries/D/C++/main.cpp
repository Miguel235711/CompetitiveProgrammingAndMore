#include <bits/stdc++.h>
#define maxL 500008

using namespace std;

int n;
int arr[maxL];
struct node {
    int l,r;
    int sums[2];
};
node seg[maxL*4];

int sum(int par,int index,int l,int r){
    if(l>seg[index].r || r < seg[index].l)
        return 0;
    if(l<=seg[index].l && seg[index].r <= r)
        return seg[index].sums[par];
    return sum(par,index*2,l,r)+sum(par,index*2+1,l,r);
}

pair<int,int> build(int index,int l, int r){
    seg[index].l = l, seg[index].r = r;
    //cout << "l: " << l << " r: " << r << "\n";
    if(l!=r){
        int mid = (l+r)>>1;
        auto a = build(index*2,l,mid), b = build(index*2+1,mid+1,r);;
        seg[index].sums[0] = a.first+b.first;
        seg[index].sums[1] = a.second+b.second;
    }else{
        seg[index].sums[0]=l&1?-arr[l]:arr[l];
        seg[index].sums[1]=l&1?arr[l]:-arr[l];
    }
    //cout << "index: " << index << " sum: " << seg[index].sum << "\n";
    return make_pair(seg[index].sums[0],seg[index].sums[1]);
}

pair<int,int> update(int index,int i, int x){
    if(seg[index].r<i||i<seg[index].l)
        return make_pair(seg[index].sums[0],seg[index].sums[1]);
    if(seg[index].l==seg[index].r){
        seg[index].sums[0] = i&1?-x:x;
        seg[index].sums[1] = i&1?x:-x;
        return make_pair(seg[index].sums[0],seg[index].sums[1]);
    }
    auto lA = update(index*2,i,x), rA = update(index*2+1,i,x);
    seg[index].sums[0] = lA.first + rA.first,
    seg[index].sums[1] = lA.second + rA.second;
    return make_pair(seg[index].sums[0],seg[index].sums[1]);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n; 
    for(int i = 1 ; i <= n ; i ++)
        cin >> arr[i];
    build(1,1,n);
    //cout << seg[0].sum << "\n";
    /*for(int i = 0 ; i<10 ; i++)
        cout << "seg: " << seg[i].l << " " << seg[i].r << " " << seg[i].sum << "\n";*/
    int m ; 
    cin >> m ; 
    int q,a,b;
    while(m--){
        cin>>q>>a>>b;
        if(!q)
            /*cout << "b-arr[a]: " << b-arr[a] << "\n",*/update(1,a,b);
        else
            /*cout << "a: " << a << "b: " << b << "\n",*/cout << sum(a&1,1,a,b) << "\n";
    }
    return 0;
}