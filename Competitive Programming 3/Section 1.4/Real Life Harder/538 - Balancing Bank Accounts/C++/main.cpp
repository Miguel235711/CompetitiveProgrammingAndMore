#include<bits/stdc++.h>

using namespace std;

int n,t;
string line;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int cs=1;cin>>n>>t,n;cs++){
        printf("Case #%d\n",cs);
        map<string,int> balance;
        while(n--){
            cin >> line;
            balance[line];
        }
        while(t--){
            string n1,n2;
            int amount;
            cin >> n1 >> n2 >> amount;
            balance[n1]-=amount;
            balance[n2]+=amount;
        }
        vector<pair<string,int> > positives,negatives;
        int iP=0,iN=0;
        for(auto b : balance){
            string name = b.first;
            int amount = b.second;
            if(amount>0)
                positives.push_back(make_pair(name,amount));
            else if(amount<0)
                negatives.push_back(make_pair(name,-amount));
            string aS,bS;
            amount = 0 ;
            for(;iP<positives.size()&&iN<negatives.size();iN++,iP++){
                aS = positives[iP].first;
                bS = negatives[iN].first;
                if(positives[iP].second<negatives[iN].second)
                    negatives[iN--].second -= amount = positives[iP].second;
                else if(positives[iP].second>negatives[iN].second)
                    positives[iP--].second -= amount = negatives[iN].second;
                else
                    amount = positives[iP].second;
                printf("%s %s %d\n",aS.c_str(),bS.c_str(),amount);
            }
        }
        printf("\n");
    }
    return 0;
}