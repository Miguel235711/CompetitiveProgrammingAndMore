#include<bits/stdc++.h>
#define limTime 18001

using namespace std;

string twoDigits(int x){
    return (x<10?"0":"")+to_string(x);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x=-1,lastX;
    while(1){
        vector<pair<int,int> >lights;
        while(1){
            lastX = x;
            cin >> x;
            if(x==0){
                if(lastX==0)
                    return 0;
                break;
            }
            lights.push_back(make_pair(x,0));
        }
        //process lights
        sort(lights.begin(),lights.end());
        //simulate packs
        auto done = false;
        auto smallest = lights[0];
        for(int p=2;smallest.first*p+1 <= limTime; p+=2){
            int limT = min(smallest.first*(p+1)-4,limTime+1);
            for(int t = smallest.first*p+1;t<limT;t++){
                auto allInT = true;
                for(size_t j = 1 ; j < lights.size() ; j++){
                    for(;lights[j].first*(lights[j].second+1)-5<t;lights[j].second+=2);
                    if(t < lights[j].second*lights[j].first+1||t>(lights[j].second+1)*lights[j].first-5)
                        allInT = false;
                }
                if(allInT){
                    t--;
                    cout <<  twoDigits(t/3600) << ":" << twoDigits((t-t/3600*3600)/60) << ":" << twoDigits(t%60) << "\n";
                    done=true;
                    break;
                }
            }
            if(done)
                break;
        }
        if(!done)
            cout << "Signals fail to synchronise in 5 hours\n";
    }
    return 0;
}