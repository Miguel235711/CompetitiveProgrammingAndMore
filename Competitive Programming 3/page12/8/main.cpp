#include <bits/stdc++.h>

using namespace std;

vector<int>Set;
int n;

void printSet(){
    cout << "{";
    for(int i = Set.size()-1 ; i > -1 ; i -- ){
        cout << Set[i] ;
        if(i!=0){
            cout << ", ";
        }
    }
    cout << "}\n";
}

void f(int x){
    if(x<0){
        printSet();
    }else{
        f(x-1);//do not take
        Set.push_back(x);
        f(x-1);//take
        Set.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ; 
    f(n-1);
    return 0;
}