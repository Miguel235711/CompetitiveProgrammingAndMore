#include <bits/stdc++.h>
#define maxL 500008

using namespace std;

int n;
int64_t arr[maxL];
struct node {
    int l,r;
    int64_t sum;
};
node seg[maxL*4];

int64_t sum(int index,int l,int r){
    if(l>seg[index].r || r < seg[index].l)
        return 0;
    if(l<=seg[index].l && seg[index].r <= r)
        return seg[index].sum;
    return sum(index*2,l,r)+sum(index*2+1,l,r);
}

int64_t build(int index,int l, int r){
    seg[index].l = l, seg[index].r = r;
    //cout << "l: " << l << " r: " << r << "\n";
    if(l!=r){
        int mid = (l+r)>>1;
        seg[index].sum=build(index*2,l,mid)+build(index*2+1,mid+1,r);
    }else
        seg[index].sum=arr[l];
    //cout << "index: " << index << " sum: " << seg[index].sum << "\n";
    return seg[index].sum;
}

void update(int index,int i, int delta){
    seg[index].sum += delta;
    if(seg[index].l==seg[index].r)
        return;
    if(seg[index*2].l<=i&&i<=seg[index*2].r)
        update(index*2,i,delta);
    else
        update(index*2+1,i,delta);
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
    string q;
    int a,b;
    while(cin>>q){
        cin>>a>>b;
        if(q=="set")
            /*cout << "b-arr[a]: " << b-arr[a] << "\n",*/update(1,a,b-arr[a]),arr[a]=b;
        else
            /*cout << "a: " << a << "b: " << b << "\n",*/cout << sum(1,a,b) << "\n";
    }
    return 0;
}