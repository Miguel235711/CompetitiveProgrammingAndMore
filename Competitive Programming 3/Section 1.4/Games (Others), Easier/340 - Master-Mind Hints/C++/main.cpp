#include<bits/stdc++.h>

#define lim 1000

using namespace std;

int N,s[lim],g[lim];

bool readG(){
    for(int i = 0 ; i < N ; i ++)
        cin >> g[i];
    return g[0];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int cs=1;cin>>N,N;cs++){
        cout << "Game " << cs << ":\n";
        for(int i = 0 ; i < N ; i ++)
            cin >> s[i];
        while(readG()){
            int strong=0,weak=0;
            multiset<int>numbersInS;
            for(int i = 0 ; i < N ; i++)
                if(s[i]==g[i])
                    strong++;
                else
                    numbersInS.insert(s[i]);
            for(int i = 0 ; i < N ; i ++){
                auto it = numbersInS.find(g[i]);
                if(s[i]!=g[i]&&it!=numbersInS.end()){
                    weak++;
                    numbersInS.erase(it);
                }
            }
            cout << "    (" << strong << "," << weak << ")\n";
        }
    }
    return 0;
}