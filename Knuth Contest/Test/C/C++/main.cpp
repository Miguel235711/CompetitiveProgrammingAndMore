#include<bits/stdc++.h>

using namespace std;

int people[4],h;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i = 0 ; i < 4 ; i ++)
        cin >> people[i];
    cin >> h;
    sort(people,people+4);
    cout << (people[3]+people[2]+people[1]>=h?"WAW":"AWW") << "\n";
    return 0;
}