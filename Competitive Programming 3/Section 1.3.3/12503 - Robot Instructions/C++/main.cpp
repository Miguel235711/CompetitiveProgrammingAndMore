#include<bits/stdc++.h>

using namespace std;

int dif[100];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n;
    cin >> t ; 
    while(t--){
        cin >> n ; 
        cin.ignore();
        int ans = 0 ; 
        for(int i = 0 ; i < n ; i ++){
            string line ; 
            getline(cin,line);
            if(line[0]=='L'){
                dif[i]=-1;
            }else if(line[0]=='R'){
                dif[i]=1;
            }else{
                smatch m;
                regex_search(line,m,regex("[0-9]"));
                dif[i]=dif[stoi(line.substr(m.position(0),line.size()-1))-1];
            }
            ans+=dif[i];
        }
        cout << ans << "\n";
    }
    return 0;
}