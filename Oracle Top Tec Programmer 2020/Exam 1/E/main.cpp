#include<bits/stdc++.h>

using namespace std;

int bestIncrease = 0 ; 

char category(int x){
    int r = x%4;
    if(r==0){
        return 'D';
    }
    if(r==1){
        return 'A';
    }
    if(r==3){
        return 'B';
    }
    return 'C';
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x ; 
    cin >> x ;
    char initialCategory = category(x);  
    for(int increase = 1 ; increase <= 2 ; increase ++ ){
        if(category(x+increase)<initialCategory){
            bestIncrease = increase ; 
            initialCategory = category(x+increase);
        }
    }
    cout << bestIncrease << " " << initialCategory << "\n";
    return 0 ;
}