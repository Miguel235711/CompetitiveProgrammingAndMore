#include<bits/stdc++.h>

#define dayTimes 3

using namespace std;

const vector<pair<int,int> > timeRanges[dayTimes]={{make_pair(480,1080)},{make_pair(1080,1320)},{make_pair(1320,1439),make_pair(0,480)}};

const double rates[5][dayTimes]={{0.10,0.06,0.02},{0.25,0.15,0.05},{0.53,0.33,0.13},{0.87,0.47,0.17},{1.44,0.80,0.30}};

vector<int> getMinutes(int tB,int tE){
    vector<int>ans;
    for(int i = 0 ; i < dayTimes ; i++){
        int minutesOfDayTime=0;
        for(const pair<int,int> & tR : timeRanges[i]){
            int l = max(tR.first,tB), r = min(tR.second,tE);
            minutesOfDayTime+=max(r-l,0);
        }
        ans.push_back(minutesOfDayTime);
    }
    return ans;
}
vector<int> getMinutesMulti(const vector<pair<int,int> > & times){
    vector<int>ans(3,0);
    for(auto time: times){
        vector<int> minutes = getMinutes(time.first,time.second);
        for(int i = 0 ; i < ans.size() ; i ++)
            ans[i]+=minutes[i];
    }
    return ans;
}
int getT(int H,int M){
    return H*60+M;
}

double getCost(int stepN,const vector<int> & minutes){
    double ans = 0 ;
    for(int i = 0 ; i < minutes.size() ; i ++)
        ans+=minutes[i]*rates[stepN][i];
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    char step;
    string number;
    int bH,bM,eH,eM;
    while(cin>>step&&step!='#'){
        cin >> number;
        cin >> bH >> bM >> eH >> eM;
        int tB = getT(bH,bM) , tE = getT(eH,eM);
        vector<pair<int,int> > times;
        if(tB>=tE)
            times = {make_pair(tB,getT(23,59)),make_pair(getT(0,0),tE)};
        else
            times = {make_pair(tB,tE)};
        vector<int> minutes = getMinutesMulti(times);
        if(times.size()==2) // 29:59 to 00:00
            minutes[2]++;
        cout << right << setw(10) << number ;
        for(int m : minutes)
            cout << setw(6) << m ;
        cout << setw(3) << step << setw(8) << fixed << setprecision(2) << getCost(step-'A',minutes) << "\n";
    }
    return 0;
}