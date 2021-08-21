#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,p;
    string line;
    for(int cs=1;cin>>n>>p&&(n||p);cs++){
        float minimumCost = INT_MAX;
        int mostReq=0;
        string bestAns="";
        if(cs>1)
            cout << "\n";
        cin.ignore();
        for(int i = 0 ; i < n ; i ++){
            getline(cin,line);
        }
        for(int i = 0 ; i < p ; i ++){
            float d;
            int r;
            getline(cin,line);
            cin >> d >> r ; 
            cin.ignore();
            if(r>mostReq || (r==mostReq && minimumCost>d)){
                mostReq=r;
                minimumCost=d;
                bestAns=line;
            }
            for(int j = 0 ; j < r ; j ++){
                getline(cin,line);
            }
        }
        cout << "RFP #" << cs << "\n" << bestAns << "\n";
    }
    return 0;
}