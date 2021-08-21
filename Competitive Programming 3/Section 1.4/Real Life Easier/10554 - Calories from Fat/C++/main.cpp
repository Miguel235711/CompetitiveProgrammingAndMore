#include<bits/stdc++.h>
#define lim 5

using namespace std;

pair<double,char> amounts[lim];
int caloryGram[lim]={9,4,4,4,7};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    while(cin>>s&&s[0]!='-'){
        double totalCalories = 0 , fatCalories = 0 ;
        do{
            amounts[0].first = stoi(s.substr(0,s.size()-1)),amounts[0].second=s[s.size()-1];
            for(int i = 1 ; i < lim; i ++)
                cin >> amounts[i].first >> amounts[i].second;
            double q = 100,caloriesKnown=0;
            for(int i = 0 ; i < lim ; i ++){
                if(amounts[i].second=='g'){
                    amounts[i].second='C';
                    amounts[i].first*=caloryGram[i];
                }
                if(amounts[i].second=='C')
                    caloriesKnown += amounts[i].first;
                else
                    //percent
                    q-=amounts[i].first; 
            }
            double caloryPercent = caloriesKnown/q;
            for(int i = 0 ; i < lim ; i ++){
                if(amounts[i].second == '%')
                    amounts[i].first*= caloryPercent;
                totalCalories += amounts[i].first;
            }
            fatCalories += amounts[0].first;
        }while(cin>>s&&s[0]!='-');
        cout  << (int)round(fatCalories / totalCalories * 100) << "%\n"; 
    }
    return 0;
}