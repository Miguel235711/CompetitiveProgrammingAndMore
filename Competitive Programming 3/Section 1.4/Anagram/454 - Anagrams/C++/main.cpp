#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    string line;
    getline(cin,line);
    for(int cs = 0 ; cs < n ; cs++){
        if(cs!=0)
            cout << "\n";
        vector<pair<string,string> > pairs;
        while(getline(cin,line)&&line!=""){
            pairs.push_back(make_pair(line,line));
            //remove spaces
            pairs.back().second.erase(remove_if(pairs.back().second.begin(),pairs.back().second.end(),[](char x){
                return x==' ';
            }),pairs.back().second.end());
            //sort chars
            sort(pairs.back().second.begin(),pairs.back().second.end());
        }
        //sort phrases
        sort(pairs.begin(),pairs.end());
        //brute force
        for(size_t i = 0 ; i < pairs.size(); i++){
            for(size_t j = i+1 ; j < pairs.size(); j ++){
                if(pairs[i].second==pairs[j].second)
                    cout << pairs[i].first << " = " << pairs[j].first << "\n";
            }
        }
    }
    return 0;
}