#include<bits/stdc++.h>

using namespace std;

string getComma(int x){
    string xS = to_string(x);
    string ans = "";
    if(xS.size()<3)
        xS.insert(0,string(3-xS.size(),'0'));
    for(size_t i = 0 ; i < xS.size(); i ++){
        if(xS.size()-i==2)
            ans.push_back('.');
        else if(i!=0&&((int)xS.size()-(int)i-5)%3==0)
            ans.push_back(',');
        ans.push_back(xS[i]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,n,d;
    cin >> N;
    for(int cs = 1 ; cs <= N ; cs++){
        double mean = 0 ;
        for(int m = 0 ; m < 12 ; m++){
            cin >> n;
            cin.ignore();
            cin >> d;
            mean+= (double)(n*100 + d)/12;
        }
        //cout << fixed << setprecision(10) << mean << " rounded: " << round(mean) << "\n";
        cout << cs << " $" << getComma(round(mean)) << "\n";
    }
    return 0;
}