#include <bits/stdc++.h>

using namespace std;

typedef int64_t lli;

int toNumber(char x){
    if(x<='9')
        return x - '0';
    return x - 'A' + 10;
}

char toChar(int x){
    if(x<=9)
        return x + '0';
    return x - 10 + 'A';
}

lli fromBaseXTo10(const string & n,int x){
    int powerX=1,number=0;
    for(int i = n.size()-1;i>-1;i--){
        number+=powerX*toNumber(n[i]);
        powerX*=x;
    }
    return number;
}

string from10ToBaseY(lli nBase10,int y){
    string ans;
    while(nBase10){
        ans.push_back(toChar(nBase10%y));
        nBase10/=y;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string num;
    int x,y;
    cin >> num >> x >> y ; 
    cout << from10ToBaseY(fromBaseXTo10(num,x),y) << "\n";
    return 0;
}