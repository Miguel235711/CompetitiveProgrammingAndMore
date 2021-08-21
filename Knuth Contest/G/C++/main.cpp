#include<bits/stdc++.h>

using namespace std;

vector<string> listS;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i  < n ; i ++){
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        listS.push_back(s);
    }
    sort(listS.begin(),listS.end(),[](string a,string b){
            //cout << "sizes: " << a.size() << " " << b.size() << " a: " << a << " b: " << b << "\n";
            //cout << "comparisson: " << a.substr(0,b.size()) << " " << b << "\n";
            if((a.size()<b.size()&&b.substr(0,a.size())==a))
                return false;
            if((b.size()<a.size()&&a.substr(0,b.size())==b))
                return true;
            return a < b;
        }    
    );
    for(int i = listS.size()-1;i>-1;i--){
        cout << listS[i];
    }
    cout<<"\n";
    return 0;
}