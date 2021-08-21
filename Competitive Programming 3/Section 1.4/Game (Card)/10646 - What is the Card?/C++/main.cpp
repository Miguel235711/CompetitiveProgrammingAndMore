#include <bits/stdc++.h>

using namespace std;

int getValue(const string & card){
    if(isdigit(card[0]))
        return card[0]-'0';
    return 10;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    string card;
    cin >> t ; 
    for(int cs = 1 ; cs <= t ; cs++){
        vector<string>st;
        queue<string>temp;
        for(int i = 0 ; i < 27 ; i ++){
            cin >> card;
            st.push_back(card);
        }
        for(int i = 0 ; i < 25; i ++){
            cin >> card;
            temp.push(card);
        }
        int y=0;
        for(int i = 0 ; i < 3 ; i ++){
            int val = getValue(st.back());
            st.pop_back();
            y+=val;
            for(int j = 10 - val ; j > 0; j --)
                st.pop_back();
        }
        while(!temp.empty()){
            st.push_back(temp.front());
            temp.pop();
        }
        cout << "Case " << cs << ": " << st[y-1] << "\n";
    }
    return 0;
}