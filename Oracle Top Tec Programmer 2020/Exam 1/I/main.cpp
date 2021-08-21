#include<bits/stdc++.h>

using namespace std;

void encode(string & x){
    char last = '\0';
    int current = 0 ; 
    for(char c : x){
        if(c!=last){
            if(last!='\0'){
                cout << last << current;
            }
            current=1,last=c;
        }else{
            current++;
        }
    }
    if(last!='\0'){
        cout << last << current;
    }
}

void print(char c, int times){
    while(times--){
        cout << c ;
    }
}

void decode(string &x){
    for(int i = 0 ; i < x.size() ; i +=2){
        print(x[i],x[i+1]-'0');
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    char com  ;
    string x; 
    cin >> com >> x ;
    if(com=='E'){
        encode(x);
    }else{
        decode(x);
    }
    cout << "\n";
    return 0 ;
}