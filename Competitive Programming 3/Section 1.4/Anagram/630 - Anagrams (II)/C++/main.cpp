#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n;
    string line;
    cin>> t;
    cin.ignore();
    for(int cs=0;cs<t;cs++){
        map<string,vector<string> > anagrams;
        if(cs!=0)
            cout << "\n";
        cin.ignore();
        cin>>n;
        cin.ignore();
        //build anagram ds
        while(n--){
            getline(cin,line);
            string sortedLine = line;
            sort(sortedLine.begin(),sortedLine.end());
            anagrams[sortedLine].push_back(line);
        }
        //anagram queries
        while(getline(cin,line)&&line!="END"){
            string original = line;
            cout << "Anagrams for: " << original << "\n";
            sort(line.begin(),line.end());
            auto it = anagrams.find(line);
            if(it==anagrams.end())
                cout << "No anagrams for: " << original << "\n";
            else{
                auto vectorRef = it->second;
                for(size_t i = 0 ; i < vectorRef.size(); i++)
                    cout << setw(3) << i+1 << ") " << vectorRef[i] << "\n";
            }
        }
    }
    return 0;
}