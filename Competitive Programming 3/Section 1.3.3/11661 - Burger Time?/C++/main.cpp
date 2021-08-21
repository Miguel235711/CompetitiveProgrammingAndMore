#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int l;
    string line;
    while(cin>>l,l){
        int r=-1,d=-1,minDist=l;
        cin >> line;
        for(int i = 0 ; i < line.size();i++){
            if(line[i]=='R' || line[i]=='Z'){
                r=i;
            }
            if(line[i]=='D' || line[i]=='Z'){
                d=i;
            }
            if(r!=-1 && d!=-1){
                minDist = min(minDist,abs(r-d));
            }
        }
        cout << minDist << "\n";
    }
    return 0;
}