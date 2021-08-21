#include<bits/stdc++.h>

using namespace std;

multiset<char>current;
vector<string>names={"RAKIBUL","ANINDYA","MOSHIUR","SHIPLU","KABIR","SUNNY","OBAIDA","WASI"};
vector< multiset<char> >nameMaping;
char grid[9][9]={
    {'O','B','I','D','A','I','B','K','R'},
    {'R','K','A','U','L','H','I','S','P'},
    {'S','A','D','I','Y','A','N','N','O'},
    {'H','E','I','S','A','W','H','I','A'},
    {'I','R','A','K','I','B','U','L','S'},
    {'M','F','B','I','N','T','R','N','O'},
    {'U','T','O','Y','Z','I','F','A','H'},
    {'L','E','B','S','Y','N','U','N','E'},
    {'E','M','O','T','I','O','N','A','L'},
};
int subset(){
    //2 if complete
    //1 if partial
    //0 if nothing
    int bestAns = 0 ;
    for(int i = 0 ; i < nameMaping.size(); i ++){
        auto it = nameMaping[i].begin();
        bool noMatch=false;
        for(auto currentIt = current.begin(); currentIt!=current.end();currentIt++){
            while(it!=nameMaping[i].end()&&*currentIt!=*it){
                it++;
            }
            if(it==nameMaping[i].end()){
                noMatch=true;
                break;
            }else{
                it++;
            }
        }
        if(!noMatch){
            if(nameMaping[i].size()==current.size())
                //cout << "i: " << i << "size: " << nameMaping[i].size() << " first: " << *nameMaping[i].begin() << "second: " << *(++nameMaping[i].begin()) << "\n";
                return 2;
            bestAns=1;
        }
    }
    return bestAns;
}

void initialize(){
    for(int i = 0 ; i < names.size() ; i ++){
        multiset<char> maping;
        for(char x: names[i]){
            maping.insert(x);
        }
        nameMaping.push_back(maping);
    }
    /*for(int i = 0 ; i < nameMaping.size(); i ++){
        for(auto it = nameMaping[i].begin();it!=nameMaping[i].end();it++){
            cout << "char: " << *it << "\n";
        }
    }*/
}

int movs[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
map<string,int>aparitions;

int main(){
    ///ios_base::sync_with_stdio(0);cin.tie(0);
    initialize();
    for(int i = 0; i < 9 ; i ++){
        for(int j = 0 ; j < 9 ; j ++){
            for(int mov = 0 ; mov < 4 ; mov ++){
                    current={grid[i][j]};
                int iN=i,jN=j;
                while(1){
                    iN+=movs[mov][0];
                    jN+=movs[mov][1];
                    if(iN<0||iN>=9||jN<0||jN>=9)
                        break;
                    //cout << "iN: " << iN << " jN: " << jN << " " << grid[iN][jN] << "\n";
                    current.insert(grid[iN][jN]);
                    /*cout << "current: ";
                    for(auto it = current.begin(); it!=current.end();it++){
                        cout << *it;
                    }
                    cout << " 4: ";
                    for(auto it = nameMaping[4].begin(); it!=nameMaping[4].end(); it++){
                        cout << *it;
                    }
                    cout << "\n";*/
                    int indication = subset();
                    if(indication==2){
                        string ans;
                        for(auto it = current.begin(); it!=current.end(); it++){
                            ans.push_back(*it);
                        }
                        auto it = aparitions.find(ans);
                        if(it==aparitions.end()){
                            aparitions[ans]=1;
                        }else{
                            it->second++;
                        }
                    }else if (indication==0){
                        break;
                    }
                }
            }
        }
    }
    for(auto it = aparitions.begin(); it!=aparitions.end();it++){
        cout << "pattern: " << it->first << " aparitions: " << it->second << "\n";
    }
    return 0;
}