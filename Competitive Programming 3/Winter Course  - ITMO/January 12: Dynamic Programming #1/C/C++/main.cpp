#include<bits/stdc++.h>
#define lim 100008

using namespace std;

int n;
size_t k;

int c[lim], jumpTo[lim], jumps[lim];
struct queueE{
    int x,i,maxx,maxI;
    queueE(int x,int i,int maxx,int maxI):x(x),i(i),maxx(maxx),maxI(maxI){}
};
bool operator < (const queueE & a, const queueE & b) {
    return a.maxx < b.maxx;
}
stack<queueE> fronted, backed;

void improvedFirstE(queueE & e1, const queueE & e2){
    if(e1.maxx < e2.maxx)
        e1.maxx = e2.maxx,e1.maxI = e2.maxI;
}

void sPop(){
    ///case when fronted is empty
    if(fronted.empty())
        while(!backed.empty()){
            auto toPass = backed.top();
            toPass.maxx = toPass.x , toPass.maxI = toPass.i;
            if(!fronted.empty())
                improvedFirstE(toPass,fronted.top());
            fronted.push(toPass),backed.pop();
        }
    fronted.pop();
}

void sPush(int x,int i){
    auto newE = queueE(x,i,x,i);
    if(!backed.empty())
        improvedFirstE(newE,backed.top());
    backed.push(newE);
    if(backed.size() + fronted.size() > k )
        sPop();
}

queueE neutralQE = queueE(0,0,INT_MIN,0);

queueE mQ(){
    //cout << "problem-> fronted.top().maxx: " <<(fronted.empty() ? neutralQE : fronted.top()).maxx << " backed.top().maxx: " << (backed.empty() ? neutralQE : backed.top()).maxx << "\n";
    return max(fronted.empty() ? neutralQE : fronted.top() ,backed.empty() ? neutralQE : backed.top());
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k ; 
    for(int i = 2 ; i < n ; i ++)
        cin >> c[i];
    int ans = 0 ;
    sPush(0,n);
    for(int i = n - 1 ; i ; i --){
        auto maxQ = mQ();
        //cout << "i: " << i << " mQ: " << maxQ.maxx << " c[i]: " << c[i] << " ";
        ans = maxQ.maxx+c[i];
        //cout << "ans: " << ans << "\n";
        jumpTo[i] = maxQ.maxI;
        jumps[i] = jumps[maxQ.maxI] + 1;
        sPush(ans,i);
        //cout << "i: " << i << " memo[i]: " << memo[i] << "\n";
    }
    cout << ans << "\n" << jumps[1] << "\n";
    for(int i = 1; i ; i = jumpTo[i])
        cout << i << " ";
    cout << "\n";
    return 0;
}