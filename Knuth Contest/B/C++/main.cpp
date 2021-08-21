#include<bits/stdc++.h>

using namespace std;

map<char,int> mapToInt={
    make_pair('R',0),
    make_pair('G',1),
    make_pair('B',2),
    make_pair('Y',3)
};

int acum[4];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s ;
    cin >> s;
    /*for(int i = 0 ; i < s.size(); i ++){
        if(i!=0)
            for(int j = 0 ; j < 4 ; j++){
                acum[j][i]+=acum[j][i-1];
            }
        auto type = mapToInt[s[i]];
        acum[type][i]++;
    }*/
    int minDif = 2,maxLength=0,bestI,bestJ;
    for(int i = 0 ; i < s.size();i++){
        memset(acum,0,sizeof(acum));
        for(int j = i ; j < s.size(); j++){
            acum[mapToInt[s[j]]]++;
            int maxi=INT_MIN,mini=INT_MAX;
            for(int l = 0 ; l < 4 ; l ++){
                maxi=max(maxi,acum[l]);
                mini=min(mini,acum[l]);
            }
            int dif = maxi-mini;
            if(dif<minDif ||(dif==minDif&&maxLength<j-i)){
                minDif = dif;
                maxLength = j - i ;
                bestI=i,bestJ=j;
            }
        }
    }
    cout << minDif << " " << maxLength+1 << "\n" << bestI + 1 << " " << bestJ + 1 << "\n";
    return 0;
}