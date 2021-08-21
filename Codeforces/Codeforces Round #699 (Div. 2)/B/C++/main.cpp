#include <bits/stdc++.h>
 
using namespace std;
 
int n, ni, ki,hi;
vector<int>hills;
int search(){
    //Search first hi that hi<h1+1
    for(int i=1; i<ni; i++)
        if(hills[i]>hills[i-1])
            return i-1;
    return -2;
};
 
int solve(){
    while(ki){//while not ran of stones
        int indToFill= search();
        if(indToFill == -2) 
            return -2;
        else 
            hills[indToFill]++;
        ki--;
        if(ki==0)//ran out of stones
            return indToFill;
    }       
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>ni>>ki;
        hills.resize(ni);
        for(int j=0 ; j < ni ; j++)
            cin >> hills[j];
        cout<<solve()+1<<"\n";
    }
    return 0;
}