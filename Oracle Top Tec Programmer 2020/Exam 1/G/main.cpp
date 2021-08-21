#include<bits/stdc++.h>

using namespace std;

int n,t ;

string calcTemp(string &s, int k ){
    string  ans;
    for(int i = k ; i < n ; i ++){
        ans.push_back(s[i]);
    }
    int inc = 1 , beg = 0 ; 
    if((n-k)&1){
        //descend
        inc = - 1 ; 
        beg = k - 1 ; 
    }
    for(int i = beg ; -1<i&&i<k;i+=inc){
        ans.push_back(s[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    string s ; 
    while(t--){
        cin >> n >> s;
        //cout << "--------\n";
        string lastBest = s;
        int  bestK = 1 ; 
        for(int k = 2 ; k <= n ; k ++ ){
            string temp = calcTemp(s,k-1);
            //cout << "temp: " << temp << "\n";
            if(temp<lastBest){
                lastBest = temp;
                bestK = k ; 
            }
        }
        cout << lastBest << "\n" << bestK << "\n";
    }
    return 0 ;
}