#include <bits/stdc++.h>

using namespace std;

int numberOfDepreRecords,months;
double downPayment,loanAmount,carValue;
struct es{
    int month;
    double percentage;
}records[108];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> months >> downPayment >> loanAmount >> numberOfDepreRecords,months>=0){
        carValue = downPayment + loanAmount ; 
        downPayment = loanAmount / months;
        int currentMonth = 0 ; 
        for(int i = 0 ; i < numberOfDepreRecords ; i ++){
            cin >> records[i].month >> records[i].percentage;
        }
        records[numberOfDepreRecords].month=months+1;
        for(int i = 1 ; i <= numberOfDepreRecords; i++){
            for(; currentMonth < records[i].month; currentMonth++){
                carValue *= 1 - records[i-1].percentage;
                if(loanAmount-currentMonth*downPayment<carValue){
                    cout << currentMonth << " month" << (currentMonth!=1?"s":"") << "\n";
                    goto next;
                } 
            }
        }
        next:
        ;
    }
    return 0;
}