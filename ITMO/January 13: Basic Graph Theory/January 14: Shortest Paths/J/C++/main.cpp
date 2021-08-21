#include <bits/stdc++.h>
#define maxNodes 508
#define inf 1441

using namespace std;

int d[maxNodes],n;
struct es{
    int x,t,w;
    es(int x,int t,int w):x(x),t(t),w(w){}
};
vector<es> graph[maxNodes];

bool possible(int grams){
    grams*=100; // cups to grams
    grams += 3e6;
    fill(d+1,d+n+1,inf);
    d[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > q;
    q.push(make_pair(0,1));
    while(!q.empty()){
        auto e = q.top();
        q.pop();
        for(auto child: graph[e.second])
            if(grams <= child.w && d[child.x]>d[e.second]+child.t)
                d[child.x] = d[e.second]+child.t,q.push(make_pair(d[child.x],child.x));
    }
    //cout << "grams: " << grams << " d[n]: " << d[n] << "\n";
    return d[n] <= 1440;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m,ai,bi,ti,wi,maxWi = 0;
    cin >> n >> m ; 
    while(m--){
        cin >> ai >> bi >> ti >> wi;
        graph[ai].push_back(es(bi,ti,wi));
        graph[bi].push_back(es(ai,ti,wi));
        maxWi = max(maxWi,wi);
    }
    //binary search
    //cout << "maxWi: " << maxWi << "\n";
    int l = 0, r = max(0,(maxWi-3000000)/100);
    //cout << "l: " << l << " r: " << r << "\n";
    while(l+1<r){
        int mid = (l+r)/2;
        if(possible(mid))
            l = mid;
        else
            r = mid - 1;
    } 
    cout <<(possible(r) ? r : l) << "\n";
    return 0;
}