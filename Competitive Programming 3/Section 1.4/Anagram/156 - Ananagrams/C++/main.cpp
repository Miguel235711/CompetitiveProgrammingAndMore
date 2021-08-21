#include<bits/stdc++.h>

using namespace std;

map<string,int> sortedLowerStrings;
vector<pair<string,bool> > originalAnagram;

void processWord(string & word){
    originalAnagram.push_back(make_pair(word,false));
    transform(word.begin(),word.end(),word.begin(),[](char c){
        return tolower(c);
    });
    sort(word.begin(),word.end());
    auto it = sortedLowerStrings.find(word);
    if(it == sortedLowerStrings.end())
        sortedLowerStrings[word]=originalAnagram.size()-1;
    else
        //visit both
        originalAnagram[it->second].second=originalAnagram[originalAnagram.size()-1].second=true;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string word;
    while(cin>>word&&word[0]!='#'){
        processWord(word);
    }
    sort(originalAnagram.begin(),originalAnagram.end());
    for(auto oA : originalAnagram)
        if(!oA.second)
            cout << oA.first << "\n";
    return 0;
}