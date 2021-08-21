#include<bits/stdc++.h>
#define mp make_pair
#define se second
#define fi first

using namespace std;

typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k;
    while(cin >> n >> k,n){
        queue<pii>people;
        for(int i = 1 ; i <= n ; i ++)
            people.push(mp(i,40));
        for(int m = 1 ; !people.empty() ; m=(m%k)+1){
            int amount = m;
            while(amount&&!people.empty()){
                pii current = people.front();
                people.pop();
                int dif = min(current.se,amount);
                amount -= dif;
                current.se-=dif;
                if(current.se)
                    people.push(current);
                else
                    cout << setw(3) << current.fi; 
            }
        }
        cout << "\n";
    }
    return  0;
}