#include<bits/stdc++.h>

using namespace std ; 

int n,ai;

struct es{
    int hi,oc;
    es(){}
    es(int hi,int oc){
        this->hi=hi;
        this->oc=oc;
    }
};

int64_t checkAns(int hi,int totalOccurrences,int64_t ans){
    return max(ans,(int64_t)totalOccurrences * hi);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>n,n){
        int64_t ans = 0 ; 
        stack<es>myStack;
        for(int i = 0 ; i <= n ; i ++){
            if(i<n){
                cin >> ai;
            }else{
                ai=0;
            }
            int totalOccurrences = 0 ;
            if(!myStack.empty()&& ai<myStack.top().hi){
                //poping
                while(!myStack.empty() && myStack.top().hi>ai){
                    totalOccurrences += myStack.top().oc;
                    ans = checkAns(myStack.top().hi,totalOccurrences,ans);
                    myStack.pop();
                }
            }
            myStack.push(es(ai,totalOccurrences+1));
        }
        cout << ans << "\n";
    }
    return 0;
}