#include <bits/stdc++.h>
#define maxL 239020

using namespace std;

int n, arr[maxL],nextM[maxL],ans[maxL];
struct node {
    int l,r;
    pair<int,int> x;
};
node seg[maxL*4];

pair<int,int> maxQ(int index,int r){ ///value, index
    if(r < seg[index].l)
        return make_pair(0,0);
    if(seg[index].r <= r)
        return seg[index].x;
    return max(maxQ(index*2,r),maxQ(index*2+1,r));
}

void build(int index,int l, int r){
    seg[index].l = l, seg[index].r = r,seg[index].x.second=r,seg[index].x.first=0;
    if(l!=r){
        int mid = (l+r)>>1;
        build(index*2,l,mid),build(index*2+1,mid+1,r);
    }
}

pair<int,int> update(int index,int i, int x,int arrI){
    if(seg[index].r<i||i<seg[index].l)
        return seg[index].x;
    if(seg[index].l==seg[index].r){
        seg[index].x.first = x,seg[index].x.second=arrI;
        return seg[index].x;
    }
    return seg[index].x = max(update(index*2,i,x,arrI),update(index*2+1,i,x,arrI));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n; 
    int ind = 0 ;
    map<int,int> nums;
    set<int> ord;
    for(int i = 1 ; i <= n ; i ++){
        cin >> arr[i];
        ord.insert(arr[i]);
    }
    for(auto it = ord.begin(); it!=ord.end();++it)
        nums[*it]=++ind;
    for(int i = 1 ; i <= n ; i ++)
        arr[i]=nums[arr[i]];
    build(1,1,n);
    int longest = 0,bestB=1 ; 
    for(int i = n; i ; i --){
        auto bestAns = maxQ(1,arr[i]);
        //cout << "-> " << bestAns.first << " " << bestAns.second << "\n";
        if(bestAns.first)
            nextM[i] = bestAns.second;
        ans[i] = bestAns.first + 1;
        if(ans[i]>longest)
            longest = ans[i],bestB = i;
        //cout << "to update: " << " i : " << arr[i] << " x: " << ans[i] << " next: " << nextM[i] << "\n";
        update(1,arr[i],ans[i],i);
    }
    //cout << "bestB: " << bestB << "\n";
    cout << longest << "\n";
    /*for(int i = 1 ; i <= n ; i ++)
        cout << nextM[i] << " ";
    cout << "\n";*/
    for(;bestB;bestB = nextM[bestB]){
        cout << bestB << " ";
    }
    cout << "\n";

    //cout << seg[0].sum << "\n";
    /*for(int i = 0 ; i<10 ; i++)
        cout << "seg: " << seg[i].l << " " << seg[i].r << " " << seg[i].sum << "\n";*/
    return 0;
}