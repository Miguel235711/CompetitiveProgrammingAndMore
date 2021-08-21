#include<bits/stdc++.h>

using namespace std;

vector<string>chromatics={"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A","A#", "B"};
vector<int>increments={0,2,2,1,2,2,2,1};
vector<pair<string,set<string> > > scales;

void generateScales(){
    for(size_t i = 0 ; i < chromatics.size();i++){
        auto scaleKey = chromatics[i];
        set<string> scale;
        for(size_t j = i,k = 0 ;k < increments.size(); k++){
            j=(j+increments[k])%chromatics.size();
            scale.insert(chromatics[j]);
        }
        scales.push_back(make_pair(scaleKey,scale));
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    generateScales();
    string line;
    while(getline(cin,line)&&line!="END"){
        bool notFirst = false;
        line.push_back(' ');
        for(const auto & scale:scales){
            string current = "";
            bool validKey = true;
            for (char c: line){
                if(c==' '){
                    if(scale.second.find(current)==scale.second.end()){
                        validKey = false;
                        break;
                    }
                    current = "";
                }else
                    current.push_back(c);
            }
            if(validKey){
                if(notFirst)
                    cout<<' ';
                else
                    notFirst = true;
                cout << scale.first;
            }
        }
        cout << "\n";
    }
    return 0;
}