#include<bits/stdc++.h>
#define maxL 100008

using namespace std;

int memo[maxL][2][3]; /// 1 ,2 
int arr[maxL],n;

int invert(int x){
    return x == 2 ? 1 : 2;
}

int f(int i,bool canStay,int whichOne){ /// which one wins
    //cout << "i: " << i << " canStay: " << canStay << " whichOne: " << whichOne << "\n";
    if(i==n)///cannot take
        return /*cout << "leaft: " << invert(whichOne) << "\n" ,*/invert(whichOne);
    if(memo[i][canStay][whichOne])
        return memo[i][canStay][whichOne];
    int ne = invert(whichOne);
    int takeAll = f(i+1,arr[i+1]>1,ne);
    if(takeAll == whichOne || !canStay)
        return memo[i][canStay][whichOne]=takeAll;
    return  memo[i][canStay][whichOne]=f(i,0,ne);
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t ; 
    while(t--){
        cin >> n ; 
        for(int i = 0 ; i < n ; i ++)
            cin>>arr[i];
        memset(memo,0,sizeof(memo));
        cout << (f(0,arr[0]>1,1) == 1 ? "First" : "Second") << "\n";
    }
    return 0;
}