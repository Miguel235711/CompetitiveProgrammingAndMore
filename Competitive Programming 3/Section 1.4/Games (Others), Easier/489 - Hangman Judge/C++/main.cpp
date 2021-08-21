#include<bits/stdc++.h>

using namespace std;

int roundd;
string line;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>roundd,roundd!=-1){
        set<int> objective,visited,wrong;
        cout << "Round " << roundd << "\n";
        cin >> line;
        for(char c:line){
            objective.insert(c);
        }
        cin >> line;
        for(char c:line)
            if(objective.find(c)!=objective.end()){
                visited.insert(c);
                if(visited.size()==objective.size())
                    break;
            }else{
                wrong.insert(c);
                if(wrong.size()>6)//loses
                    break;
            }
        cout << "You " << (wrong.size()>6 ? "lose" : (visited.size()==objective.size() ? "win" : "chickened out")) << ".\n";
    }
    return 0;
}