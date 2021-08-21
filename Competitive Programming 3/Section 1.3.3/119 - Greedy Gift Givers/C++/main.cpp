#include<bits/stdc++.h>

using namespace std;

int gainLoss[12];
string personName[12];
int n;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(bool noFirst=false;cin>>n;noFirst=true){
        if(noFirst){
            cout << "\n";
        }
        map<string,int>toPosition;
        //register people
        for(int i = 0 ; i < n ; i ++){
            cin >> personName[i];
            gainLoss[i]=0;
            toPosition.insert(make_pair(personName[i],i));
        }
        //simulate
        for(int i = 0 ; i < n ; i ++){
            string person;
            cin >> person;
            int money,numberOfGifts,evenMoney;
            cin >> money>>numberOfGifts;
            evenMoney = numberOfGifts?money/numberOfGifts:0;
            gainLoss[toPosition[person]]+=-evenMoney*numberOfGifts;
            for(int j = 0 ; j < numberOfGifts; j ++){
                string toPerson;
                cin >> toPerson;
                gainLoss[toPosition[toPerson]]+=evenMoney;
            }
        }
        for(int i = 0 ; i < n ; i ++){
            cout << personName[i] << " " << gainLoss[i] << "\n";
        }
    }
    return 0;
}