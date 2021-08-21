#include<bits/stdc++.h>
#define maxLength 100008

using namespace std ; 

int n,vi,di,sqrtN;

struct part{
    int greatestDif,maxi,mini;
    part(){}
    part(int greatestDif,int maxi, int mini){
        this->greatestDif=greatestDif;
        this->maxi=maxi;
        this->mini=mini; 
    }
};

int cost[8][maxLength];
part sqrtPartitions[8][320];
int mult[7]={0,1,2,3,2,1,0};

int minusOneCircular(int day){
    day--;
    if(day==0)
        return 7;
    return day;
}

void precalculateSqrtDecomp(){
    for(int t = 1 ; t <= 7 ; t ++ ){
        for(int begPartition = t , partition = 1 ; begPartition <= n ; begPartition += sqrtN,partition++){
            int limPartition = min(begPartition + sqrtN,n+1), minimum = INT_MAX , maximum = INT_MIN , greatestDif = 0 ; 
            for(int i = begPartition ; i < limPartition ; i ++){
                greatestDif = max(cost[t][i] - minimum,greatestDif);
                minimum = min(minimum,cost[t][i]) , maximum = max(maximum,cost[t][i]);
            }
            //save data in partition
            sqrtPartitions[t][partition] = part(greatestDif,maximum,minimum);
        }
    }
}

int getPartition(int t,int pos){//pos must be valid , it may be generalized later
    return (pos-t)/sqrtN+1 ;
}

part calcPartition(int t,int & index,int dif){
    int partitionIndex = getPartition(t,index),minimum = INT_MAX , maximum = 0 , greatestDif = 0 ; 
    for(;getPartition(t,index)==partitionIndex;index += dif){
        if(dif==1){
            greatestDif = max(cost[t][index] - minimum,greatestDif);
        }else{
            greatestDif = max(maximum-cost[t][index],greatestDif);
        }
        minimum = min(minimum,cost[t][index]) , maximum = max(maximum,cost[t][index]);
    }
    return part(greatestDif,maximum,minimum);
}

int getWeekDay(int pos){
    return (pos-1) % 7 + 1;
}

int query(int s , int t ){
    //be sure to pass s < t !!!
    int weekDayS = getWeekDay(s);
    if(getPartition(weekDayS,s)+1<getPartition(weekDayS,t)){
        part subPartitionT = calcPartition(weekDayS,t,-1);
        part subPartitionS = calcPartition(weekDayS,s,1);
        int maximum = subPartitionT.maxi;
        int partitionS = getPartition(weekDayS,s), partitionT =getPartition(weekDayS,t) ;
        int ans = max(subPartitionS.greatestDif,max(subPartitionT.greatestDif,0));
        while(partitionT>=partitionS){
            ans=max(ans,max(maximum - sqrtPartitions[weekDayS][partitionT].mini,sqrtPartitions[weekDayS][partitionT].greatestDif));
            maximum = max(maximum,sqrtPartitions[weekDayS][partitionT].maxi);
            partitionT --;
        }
        ans=max(ans,maximum - subPartitionS.mini);
        return ans;
    }else{
        //bruteforce
        int ans = 0 ; 
        int maximum = cost[weekDayS][t];
        for(int i = t-1 ; i >= s ; i --){
            ans = max(maximum-cost[weekDayS][i],ans);
            maximum = max(maximum,cost[weekDayS][i]);
        }
        return ans;
    }
}

pair<int,int>queries[maxLength],cities[maxLength];
int queryAns[maxLength];

void precalculateCosts(){
    for(int i = 1 ; i <= n ; i ++){
        int day = getWeekDay(i);
        for(int t = 1 ; t <= 7 ; t ++){
            cost[t][i] = mult[day-1]*cities[i].second+cities[i].first;
            day = minusOneCircular(day);
        } 
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n , sqrtN = sqrt(n);
    for(int i = 1 ; i <= n ; i ++){
        cin >> cities[i].first >> cities[i].second ; 
    }
    precalculateCosts();
    precalculateSqrtDecomp();
    int q ; 
    cin >> q ; 
    for(int i = 1 ; i <= q ; i ++){
        cin >> queries[i].first >> queries[i].second ; 
        if(queries[i].first<queries[i].second){
            queryAns[i] = query(queries[i].first,queries[i].second);
        }
    }
    //reverse array 
    reverse(cities+1,cities+n+1);
    precalculateCosts();
    precalculateSqrtDecomp();
    for(int i = 1 ; i <= q ; i ++){
        if(queries[i].first>queries[i].second){
            cout << query(n-queries[i].first+1,n-queries[i].second+1);
        }else{
            cout << queryAns[i];
        }
        cout << "\n";
    }
    return 0;
}