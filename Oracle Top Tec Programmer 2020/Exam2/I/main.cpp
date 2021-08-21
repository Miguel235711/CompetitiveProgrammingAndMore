#include<bits/stdc++.h>

using namespace std;

struct es{
    char party;
    int wastedA,wastedB;
}result[10008];
pair<int,int> input[10008];
int p,d;
int v=0,totalWastedA=0,totalWastedB=0;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> p >> d ; 
    for(int i = 1 ; i <= p ; i ++){
        int di,ai,bi;
        cin >> di>>ai>>bi;
        input[di].first += ai;
        input[di].second += bi;
        
    }
    for(int i = 1 ; i <= d ; i ++){
        int total = input[i].first+input[i].second;
        v += total;
        if(input[i].first>input[i].second){
            result[i].party = 'A';
            result[i].wastedB += input[i].second;
            result[i].wastedA += input[i].first - total / 2 - 1; 
        }else{
            result[i].party = 'B';
            result[i].wastedA += input[i].first;
            result[i].wastedB +=  input[i].second - total/2 - 1 ; 
        }
        totalWastedA += result[i].wastedA ; 
        totalWastedB += result[i].wastedB;
    }
    for(int i = 1 ; i <= d ; i ++){
        cout << result[i].party << " " << result[i].wastedA << " " << result[i].wastedB << "\n";
    }
    cout << fixed << setprecision(10) << (double) abs(totalWastedA-totalWastedB) / v << "\n";
    return 0;
}