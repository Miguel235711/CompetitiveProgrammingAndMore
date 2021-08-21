#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t ; 
    cin >> t ; 
    for(int cs = 1 ; cs <= t ; cs++){
        queue<string> pages;
        string page;
        int maximum = 0,vi ; 
        for(int i = 0 ; i < 10 ; i ++){
            cin >> page >> vi;
            if(maximum<vi){
                maximum = vi;
                while(!pages.empty())
                    pages.pop();
            }
            if(maximum==vi){
                pages.push(page);
            }
        }
        cout << "Case #" << cs << ":\n";
        while(!pages.empty()){
            cout << pages.front() << "\n";
            pages.pop();
        }
    }
    return 0;
}