#include<bits/stdc++.h>

#define notesN 12

using namespace std;

int diffs[7]={0,2,2,1,2,2,2};
string notes[2][12]={{"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"},{"C","Db","D","Eb","Fb","F","Gb","G","Ab","A","Bb","Cb"}};
map<string,pair<map<string,int> , vector<string> > > scales;
map<string,int> ordinalToN={make_pair("OCTAVE",0),make_pair("SECOND",1),make_pair("THIRD",2),make_pair("FOURTH",3)
,make_pair("FIFTH",4),make_pair("SIXTH",5),make_pair("SEVENTH",6)};

void generateScales(){
    for(int i = 0 ; i < notesN;i++){
        int s = notes[0][i].size()==1 || notes[0][i][1]!='#' ? 0 : 1;
        int j = i;
        map<string,int> scale;
        vector<string> scalePos;
        for(int c = 0 ; c < 7 ; c++){
            j=(j+diffs[c])%notesN;
            auto chosen = notes[s][j];
            if(chosen =="A#" && notes[s][i]=="F")
                chosen="Bb";
            scale[chosen]=c;
            scalePos.push_back(chosen);
        }
        scales[notes[s][i]]=make_pair(scale,scalePos);
    }
}

int adjust(int x){
    return x < 0 ? 7 + x : x%7;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    generateScales();
    string line;
    while(cin>>line){
        cout << "Key of " << line << "\n";
        auto scalePair = scales[line];
        cin.ignore();
        getline(cin,line);
        line.push_back(';');
        string current;
        vector<string> query;
        for(char c: line){
            if(c==' '||c==';'){
                query.push_back(current);
                current="";
                if(c==';'){
                    //process
                    cout <<  query[0] << ": ";
                    auto it = scalePair.first.find(query[0]);
                    if(it == scalePair.first.end())
                        cout << "invalid note for this key";
                    else
                        cout << query[1] << " " << query[2] << " > " << scalePair.second[adjust(scalePair.first[query[0]]+ordinalToN[query[2]]*(query[1]=="UP"?1:-1))];
                    query.clear();
                    cout << "\n";
                }
            }else
                current.push_back(c);
        }
        cout <<"\n";
    }
    return 0;
}