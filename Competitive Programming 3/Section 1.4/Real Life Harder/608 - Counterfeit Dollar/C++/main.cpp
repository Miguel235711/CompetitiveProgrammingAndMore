#include<bits/stdc++.h>

using namespace std;

int candidates[12];
int unbalancedTimes[12];
string a,b,signalS,ab;

void process(const string & s,bool expected){
    for(auto c:s){
        if(candidates[c-'A']!=expected&&candidates[c-'A']!=-1)
            unbalancedTimes[c-'A']=4;
        else
            candidates[c-'A']=expected;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(candidates,-1,sizeof(candidates));
        memset(unbalancedTimes,0,sizeof(unbalancedTimes));
        int  unbalancedTotal=0;
        for(int i = 0 ; i < 3 ; i ++){
            cin >> a >> b >> signalS;
            ab=a+b;
            if(signalS == "even")
                //discard
                for(auto c:ab)
                    unbalancedTimes[c-'A']=4;
            else{
                unbalancedTotal++;
                for(auto c:ab)
                    unbalancedTimes[c-'A']++;
                if (signalS == "up")
                    swap(a,b);
                //a is for lighter (true), b is for heavier (false)
                process(a,true);
                process(b,false);
            }
        }
        for(int c = 0;c<12;c++){
            if(unbalancedTimes[c]==unbalancedTotal){
                printf("%c is the counterfeit coin and it is %s.\n",c+'A',(candidates[c]?"light":"heavy"));
                break;
            }
        }
    }
}