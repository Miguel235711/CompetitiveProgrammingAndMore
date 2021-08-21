#include <bits/stdc++.h>

using namespace std;

map<string,int> mapToPoints={
    make_pair("king",9),
    make_pair("queen",7),
    make_pair("knight",5),
    make_pair("jack",3)
};
set<string> mapToPointsOudlers={
    "fool",
    "one of trumps",
    "twenty-one of trumps"
};
int pointsToWin[4]={112,102,82,72},t;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    for(int cs=1;cs<=t;cs++){
        if(cs>1)
            cout << "\n";
        cout << "Hand #" << cs << "\n";
        int points=0,oudlers=0,n;
        cin >> n;
        string card;
        cin.ignore();
        while(n--){
            getline(cin,card);
            auto begCard = card.substr(0,card.find(' '));
            //check if it is oudler
            if(mapToPointsOudlers.find(card)!=mapToPointsOudlers.end()){
                points+=9;
                oudlers++;
            }else{
                //sum points
                auto it = mapToPoints.find(begCard);
                if(it==mapToPoints.end()){
                    points++;
                }else{
                    points+=it->second;
                }
            }
        }
        int dif = abs(pointsToWin[oudlers]-points);
        cout << "Game " << (points<pointsToWin[oudlers]?"lost":"won") << " by " << (float)dif/2 << " point(s).\n";
    }
    return 0;
}