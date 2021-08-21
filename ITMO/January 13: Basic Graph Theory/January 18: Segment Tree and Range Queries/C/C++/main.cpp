#include <bits/stdc++.h>
#define maxL 500008

using namespace std;

int n;
int arr[maxL];
struct node {
    int l,r;
    int minX;
};
node seg[maxL*4];

int minQ(int index,int l,int r){
    if(l>seg[index].r || r < seg[index].l)
        return INT_MAX;
    if(l<=seg[index].l && seg[index].r <= r)
        return seg[index].minX;
    return min(minQ(index*2,l,r),minQ(index*2+1,l,r));
}

int build(int index,int l, int r){
    seg[index].l = l, seg[index].r = r;
    //cout << "l: " << l << " r: " << r << "\n";
    if(l!=r){
        int mid = (l+r)>>1;
        seg[index].minX=min(build(index*2,l,mid),build(index*2+1,mid+1,r));
    }else
        seg[index].minX=arr[l];
    //cout << "index: " << index << " sum: " << seg[index].sum << "\n";
    return seg[index].minX;
}

int update(int index,int i, int x){
    if(seg[index].r<i||i<seg[index].l)
        return seg[index].minX;
    if(seg[index].l==seg[index].r){
        seg[index].minX = x;
        return x;
    }
    return seg[index].minX = min(update(index*2,i,x),update(index*2+1,i,x));
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
            /*cout << "b-arr[a]: " << b-arr[a] << "\n",*/update(1,a,b);
        else
            /*cout << "a: " << a << "b: " << b << "\n",*/cout << minQ(1,a,b) << "\n";
    }
    return 0;
}