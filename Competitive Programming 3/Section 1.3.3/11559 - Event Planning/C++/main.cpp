#include<iostream>

using namespace std;

int n,b,h,w;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>n>>b>>h>>w){
        int minAns = b+1;
        for(int ih = 0 ; ih < h ; ih++){
            int pi ; 
            cin >> pi;
            bool possible = false;
            for(int jw = 0 ; jw < w ; jw++){
                int wc;
                cin >> wc;
                if(wc>=n)
                    possible=true;
            }
            if(possible&&pi*n<minAns){
                minAns = pi*n;
            }
        }
        cout << (minAns==b+1?"stay home":to_string(minAns))<<"\n";
    }
    return 0;
}