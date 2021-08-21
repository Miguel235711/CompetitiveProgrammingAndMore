#include<bits/stdc++.h>

using namespace std;

const int hundredLim = 108;

int memo[18][hundredLim][hundredLim],T,P;

int difficulties[hundredLim], scores[hundredLim]; ///problems data, acumulated
int energies[18]; /// members data

int allVisited; ///calc in reading 

int f(int ti,int pi, int visT){ //ti is the team member, pi is the problem, visT is the remaining team members
    if(pi == P || visT == allVisited) ///all problems passed or all members used
        return 0;
    if(memo[ti][pi][visT]!=-1)
        return memo[ti][pi][visT];
    int ans = 0 ;
    if(difficulties[pi]-difficulties[pi-1]<=energies[ti]){
        ///solve the most problems for this member with binary search
        int l = pi , r = P - 1; 
        while(l+1 < r){
            int mid = (l + r) >> 1 ; 
            if(difficulties[mid]-difficulties[pi-1]>energies[ti]) // if member cannot solve those problems
                r = mid; 
            else
                l = mid;
        }
        //cout << "current team member: " << ti << " r: " << r << "l: " << l << "\n";
        ///use subarray that maximizes
        if(difficulties[r]-difficulties[pi-1]<=energies[ti]) {
            //cout << "chosen current team member: " << ti << " r: " << r << "\n";
            ans = max(f(ti,r+1,visT)+scores[r]-scores[pi-1],ans);
        }else if (difficulties[l]-difficulties[pi-1]<=energies[ti])
            ans = max(f(ti,l+1,visT)+scores[l]-scores[pi-1],ans);
    }
    ///jump problem
    ans=max(f(ti,pi+1,visT),ans);
    ///pass to other member
    for(int nextTi = 0 ;nextTi<T;nextTi++){
        if((visT | (1<<nextTi)) !=visT){ ///if not already used
            //cout << "going to try member: " << nextTi << "\n";
            ans = max ( f(nextTi,pi,visT | (1<<nextTi)),ans);
        }
    }
    return memo[ti][pi][visT] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> T >> P ; 
    allVisited = ( 1 << T ) - 1;
    for(int i = 0 ; i < T ; i ++)
        cin >> energies[i];
    for(int i = 0 ; i < P ; i ++){
        cin >> difficulties[i];
        if(i)
            difficulties[i]+=difficulties[i-1];
    }
    for(int i = 0 ; i < P ; i ++){
        cin >> scores[i];
        if(i)
            scores[i]+=scores[i-1];
    }
    memset(memo,-1,sizeof(memo));
    cout << f(0,0,0) << "\n";
    return 0;
}