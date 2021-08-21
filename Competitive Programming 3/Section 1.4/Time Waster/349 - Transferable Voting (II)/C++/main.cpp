#include<bits/stdc++.h>

#define mp make_pair 
#define pb push_back 
#define MAX(a, b) a = max(a, b) 
#define MIN(a, b) a = min(a, b) 
#define SQR(x) ((LL)(x) * (x)) 
#define RESET(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end() 
#define SORT(v) sort(ALL(v)) 
#define PERMUTE next_permutation
#define fi first 
#define se second

#define MOD 1000000009 //1E9+9

using namespace std;

typedef int64_t i64;

typedef pair<i64,i64> p64;
typedef vector<i64> v64;
typedef vector<p64>  v6464;
typedef vector < v64 > vv64;

typedef double dle;
typedef long double ldle;

typedef pair<int,int> pii; 
typedef vector<int> vi;
typedef vector< pii > vii;
typedef vector< vi > vvi;


typedef pair<string,string> pss;
typedef vector<string> vs;
typedef vector<pss> vss;

typedef pair<int,string> pis;
typedef vector<pis> vis;
typedef pair<string,int> psi;
typedef vector<psi> vsi;

typedef map<string,string> mss;
typedef map<int,string> mis;
typedef map<string,int> msi;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    size_t c,n,x;
    string tab(3,' ');
    for(int cs=1;cin>>c>>n,c||n;cs++){
        vector<queue<int> > ballots;
        for(size_t i = 0 ; i < n ; i ++){
            queue<int> ballot;
            bool visBallot[c+1];
            memset(visBallot,0,sizeof(visBallot));
            bool stillValid = true;
            for(size_t j = 0; j < c ; j++){
                cin >> x;
                if(stillValid){
                    if(x<1||x>c||visBallot[x])
                        stillValid=false;
                    else{
                        //still valid
                        visBallot[x]=true;
                        ballot.push(x);
                    }
                }
            }
            if(stillValid)
                ballots.pb(ballot);
        }
        cout << "Election #" << cs << "\n"; 
        if(n!=ballots.size())
            cout << tab << n - ballots.size() << " bad ballot(s)" << "\n";
        int ballotSizeOver2 = ballots.size() >> 1;
        //process
        bool eliminated[c+1];
        memset(eliminated,0,sizeof(eliminated));
        while(1){
            //remove eliminated, while counting min and maximum
            map<int,int>countOfCandidates;
            int miniCandidate=-1,maxiCandidate=-1;
            size_t maxCandidatesN=0;
            for(auto & ballot : ballots){
                //remove eliminated
                while(eliminated[ballot.front()])
                    ballot.pop();
                //count vote
                countOfCandidates[ballot.front()]++;
                if(miniCandidate==-1||countOfCandidates[ballot.front()]<countOfCandidates[miniCandidate])
                    miniCandidate = ballot.front();
                if(maxiCandidate==-1||ballot.front()==maxiCandidate||countOfCandidates[ballot.front()]>countOfCandidates[maxiCandidate])
                    maxiCandidate = ballot.front(),maxCandidatesN=1;
                else if(ballot.front()!=maxiCandidate&&countOfCandidates[ballot.front()]==countOfCandidates[maxiCandidate])
                    maxCandidatesN++;
            }
            if(maxCandidatesN==1&&countOfCandidates[maxiCandidate]>ballotSizeOver2){
                //win
                cout << tab << "Candidate " << maxiCandidate << " is elected.\n";
                break;
            }else if(maxCandidatesN==countOfCandidates.size()){
                //tie
                cout << tab << "The following candidates are tied:";
                for(const auto & candidate : countOfCandidates)
                    cout << " " << candidate.first;
                cout << "\n";
                break;
            }else
                //remove minimum
                eliminated[miniCandidate]=true;
        }
    }
    return 0;
}