#include<bits/stdc++.h>

using namespace std;

int getNormalized(string time){
    return (stoi(time.substr(0,2))-10)*60 + stoi(time.substr(3,2));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int cs=1,s;cin>>s;cs++){
        vector<pair<int,int> > schedule;
        while(s--){
            string begin,end;
            cin >> begin >> end;
            schedule.push_back(make_pair(getNormalized(begin),getNormalized(end)));
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        sort(schedule.begin(),schedule.end());
        schedule.push_back(make_pair(480,480));
        int lastBeg = 0 , longestNap = 0 , bestBeg = 0 , bestEnd = 0 ;
        for(auto ap : schedule){
            if(ap.first-lastBeg > longestNap){
                longestNap = ap.first - lastBeg;
                bestBeg = lastBeg;
                bestEnd = ap.first;
            }
            lastBeg = ap.second;
        }
        int duration = bestEnd - bestBeg;
        printf("Day #%d: the longest nap starts at %02d:%02d and will last for %s%d minutes.\n",cs,10+bestBeg/60,bestBeg%60,(duration > 59 ? to_string(duration/60)+" hours and " : "").c_str(),duration%60);
    }
    return 0;
}