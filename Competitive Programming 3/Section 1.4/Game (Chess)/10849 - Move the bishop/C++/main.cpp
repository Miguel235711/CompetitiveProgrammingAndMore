#include<bits/stdc++.h>

using namespace std;

bool getColor(int i,int j,int n){
    int64_t cell = (int64_t)n * i + j;
    if((n&1)||!(i&1))
        return cell&1;
    return !(cell&1);  
}
bool sameCross(int i,int j,int iO, int jO){
    return abs(iO-i)==abs(jO-j);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int c,t,n,i,j,iO,jO;
    cin>>c;
    while(c--){
        cin >> t >> n;
        while(t--){
            cin>>i>>j>>iO>>jO;
            string ans = "no move";
            if(getColor(i,j,n)==getColor(iO,jO,n))
                if(i==iO&&j==jO)
                    ans="0";
                else if(sameCross(i,j,iO,jO))
                    ans="1";
                else
                    ans="2";
            cout << ans << "\n";
        }
    }
    return 0;
}