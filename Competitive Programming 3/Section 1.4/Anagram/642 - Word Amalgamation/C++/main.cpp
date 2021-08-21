#include<bits/stdc++.h>

using namespace std;

string line;
map<string,vector<string> >anagrams;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>line&&line[0]!='X'){
        string sortedLine(line);
        sort(sortedLine.begin(),sortedLine.end());
        anagrams[sortedLine].push_back(line);
    }
    //sort each vector
    for(auto & refAna: anagrams)
        sort(refAna.second.begin(),refAna.second.end());
    //answer anagram queries
    while(cin>>line&&line[0]!='X'){
        sort(line.begin(),line.end());
        auto it = anagrams.find(line);
        if(it==anagrams.end())
            cout << "NOT A VALID WORD\n";
        else{
            for(auto element: it->second)
                cout << element << "\n";
        }
        cout << "******\n";
    }
    return 0;
}