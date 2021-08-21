#include<bits/stdc++.h>
#define maxL 10008
 
using namespace std;
 
int depth[maxL],parent[maxL],n,m;
pair<int,int> vertices[maxL];

double prim(){
    vector<int> ds(n);
    fill(ds.begin(),ds.end(),8e8+1);
    vector<bool> used(n);
    ds[0]=0; 
    double ans = 0 ;
    for(int i = 0 ; i < n ; i ++){
        int mini = 8e8+1,nex = 0;
        for(int j = 0 ; j < n ; j ++)
            if(!used[j]&&mini>ds[j])
                mini = ds[j],nex = j;
        used[nex]=1;
        ans+=sqrt(mini);
        for(int j = 0 ; j < n ; j++)
            if(!used[j])
                ds[j]=min(ds[j],(int)pow(vertices[nex].first-vertices[j].first,2)+(int)pow(vertices[nex].second-vertices[j].second,2));
    }
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
        depth[i]=1,parent[i]=i;
    for(int i = 0 ; i < n ; i++)
        cin >> vertices[i].first >> vertices[i].second;
    cout << fixed << setprecision(6) << prim() << "\n";
    return 0;
}