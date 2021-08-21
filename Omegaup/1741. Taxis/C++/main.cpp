#include<bits/stdc++.h>
#define maxL 100008

using namespace std;

struct es{
    int64_t p,c;
    bool operator<(es other)const{
        return p<other.p;
    }
}a[maxL];

int64_t dp[maxL];
deque <int> inds;

int64_t cost(int p1,int p2){ ///positions
    return pow(p2-p1,2);
}
int64_t totalCost(int i,int j){ ///indexes
    return cost(a[i].p,a[j].p)+dp[j];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin >> n >> m;
    int64_t ans = LLONG_MAX;
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i].p >> a[i].c;
    sort(a,a+n);
    for(int i = n - 1 ; i>-1 ; i --){
        ///pop deque back
        while(inds.size()>1){
            int b0 = inds.back();
            inds.pop_back();
            if(totalCost(i,inds.back())>=totalCost(i,b0)){
                inds.push_back(b0);
                break;
            }
        }
        for(;inds.size()>1&&totalCost(i,inds.back())>totalCost(i,inds.front());inds.pop_back());
        dp[i] = min(cost(a[i].p,m),!inds.empty()?min(totalCost(i,inds.back()),totalCost(i,inds.front())):(int64_t)LLONG_MAX) + a[i].c;
        if(a[i].p==0)
            ans = min(dp[i],ans);
        //cout << "cost(p[i],m): " << cost(p[i],m) << "\n";
        ///pop greaters
        for(;!inds.empty()&&dp[i]<=dp[inds.front()];inds.pop_front());
        //insert in front
        inds.push_front(i);
    }
    cout << ans << "\n";
    return 0;
}