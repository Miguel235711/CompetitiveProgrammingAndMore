#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(1){
        vector< pair<int,char> >guesses;
        int guessN;
        while(cin>>guessN){
            if(guessN==0)
                return 0;
            string line;
            cin.ignore();
            getline(cin,line);
            char response = line[4];
            if(response=='t'){
                bool honest=true;
                for(auto el:guesses){
                    if((el.second=='h'&&el.first<=guessN)||(el.second=='l'&&el.first>=guessN)){
                        honest=false;
                        break;
                    }
                }
                cout<<"Stan "<<(honest?"may be honest":"is dishonest")<<"\n";
                break;
            }else{
                guesses.push_back(make_pair(guessN,response));
            }
        }
    }
    return 0;
}