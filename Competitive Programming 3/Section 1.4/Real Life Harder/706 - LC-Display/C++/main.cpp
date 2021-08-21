#include<bits/stdc++.h>

using namespace std;

string digit[10][5]={
    {
        " - ",
        "| |",
        "   ",
        "| |",
        " - "
    },
    {
        "   ",
        "  |",
        "   ",
        "  |",
        "   "
    },
    {
        " - ",
        "  |",
        " - ",
        "|  ",
        " - "
    },
    {
        " - ",
        "  |",
        " - ",
        "  |",
        " - "
    },
    {
        "   ",
        "| |",
        " - ",
        "  |",
        "   "
    },
    {
        " - ",
        "|  ",
        " - ",
        "  |",
        " - "
    },
    {
        " - ",
        "|  ",
        " - ",
        "| |",
        " - "
    },
    {
        " - ",
        "  |",
        "   ",
        "  |",
        "   "
    },
    {
        " - ",
        "| |",
        " - ",
        "| |",
        " - "
    },
    {
        " - ",
        "| |",
        " - ",
        "  |",
        " - "
    },
};



bool rows[5]={0,1,0,1,0};
void addD(int s,int n,string * ans,bool noLast){
    for(int i = 0,iR = 0 ; i < 5 ; i ++){
        int limI = rows[i] ? s : 1;
        for(int repI = 0 ; repI < limI ; repI++,iR++){
            for(int j = 0 ; j < 3 ; j ++){
                int limJ = j==1 ? s : 1;
                for(int repJ = 0 ; repJ < limJ ; repJ++)
                    ans[iR].push_back(digit[n][i][j]);
            }
            if(noLast)
                ans[iR].push_back(' ');
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string n;
    int s;
    while(cin >> s >> n,s){
        int rowsR = (s<<1)+3;
        string ans[rowsR];
        for(size_t i = 0 ; i < n.size();i++)
            addD(s,n[i]-'0',ans,i+1!=n.size());
        for(int i = 0 ; i  < rowsR ; i++)
            cout << ans[i] << "\n";
        cout << "\n";
    }
    return 0;
}