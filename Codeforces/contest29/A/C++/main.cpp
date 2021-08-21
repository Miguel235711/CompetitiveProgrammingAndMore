#include<bits/stdc++.h>

using namespace std;

map<int,set<int> > spittedBy;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,xi,di;
    cin >> n;
    while(n--){
        cin >> xi >> di;
        int placeToSpit = xi+di;
        auto it = spittedBy.find(xi);
        if(it!=spittedBy.end()&&it->second.find(placeToSpit)!=it->second.end()){
            cout << "YES\n";
            return 0;
        }
        spittedBy[placeToSpit].insert(xi);
    }
    cout << "NO\n";
    return 0;
}