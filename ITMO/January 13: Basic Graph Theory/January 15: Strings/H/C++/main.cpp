#include<bits/stdc++.h>
#define p0 29
#define maxL 10008
#define mod 1000000009
#define inf 10000

using namespace std;

int p[maxL],h[10][maxL],k;
size_t maxSize;
vector<string> s;

void calcPs(){
    p[0]=1;
    for(size_t i = 1 ; i < maxSize ; i++)
        p[i]=(int64_t)p[i-1]*p0%mod;
} 

int f(int si,int i,int j){///inclusive
    return  i ? ((h[si][j]-(int64_t)h[si][i-1]*p[j-i+1]%mod)+mod)%mod : h[si][j];
}

void calcHashes(){
    for(int si = 0 ; si < k ; si++){
        h[si][0]=s[si][0]-'a'+1;
        for(size_t i = 1 ; i < s[si].size() ; i++)
            h[si][i] = ((int64_t)h[si][i-1]*p0%mod + s[si][i]-'a'+1)%mod;
    }
}

int indexP(int length){ ///return -1 if not, return ending index of s[0]
    ///use sorting algorithm
    if(!length)
        return 0;
    vector<pair<int,int> > ans; /// first is the hash value, second is the j-end index it belongs to (*=-1 is for si=0)
    for(int si = 0 ; si < k; si++){
        set<int> hashesUsed;
        for(size_t j = length-1;j<s[si].size();j++){
            int x = f(si,j-length+1,j);
            if(hashesUsed.find(x)==hashesUsed.end())
                ans.push_back(make_pair(x,si?-1:j)),hashesUsed.insert(x);
        }
    }
    //sort
    sort(ans.begin(),ans.end());
    /*cout << "length: " << length << "\n";
    for(auto x : ans )
        cout << "hashValue: " << x.first << " j-end index: " << x.second << "\n";*/
    ans.push_back(make_pair(mod,inf));
    int maxE = 0, maxEInd=0,cE=1,cEInd=ans[0].second; //ceInd can be calculated with min()
    for(size_t i = 1 ; i < ans.size() ; i ++){
        if(ans[i].first!=ans[i-1].first){
            if(maxE<cE)
                maxE=cE,maxEInd=cEInd;
            cE=1,cEInd=ans[i].second;
        }else
            cE++,cEInd=max(cEInd,ans[i].second);
        //cout << "hashValue: " << ans[i].first << " cE: " << cE << "\n";
    }
    //cout << "maxE: " << maxE << " maxEInd: " << maxEInd << "\n";
    return maxE == k ? maxEInd : -1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> k; 
    s.resize(k);
    size_t minSize = 10000;
    for(int i = 0 ; i < k ; i ++)
        cin >> s[i], maxSize = max(maxSize,s[i].size()), minSize = min(minSize,s[i].size());
    calcPs();
    calcHashes();
    ///binary search to find lcs with l and r inclusive
    int l = 0 , r = minSize;
    while(l + 1 < r){
        int mid = (l+r)/2;
        if(indexP(mid)!=-1)
            l = mid ; 
        else
            r = mid - 1 ; 
    }
    auto bestInd = indexP(r);
    if(bestInd==-1)
        bestInd = indexP(l),r = l;
    /*for(int i = 0 ; i < 3 ; i ++){
        int x = indexP(i);
        cout << "indexP(i): " << x << "\n"; 
    }*/
    //cout << "maxLength: " << r << "\n";
    cout << s[0].substr(bestInd-r+1,r) << "\n";
    return 0;
}