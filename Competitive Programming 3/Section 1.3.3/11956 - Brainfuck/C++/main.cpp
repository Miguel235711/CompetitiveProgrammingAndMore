#include <bits/stdc++.h>

using namespace std;

int byteArray[100];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t ; 
    cin >> t;
    string line;
    for(int cs = 1 ; cs <= t ; cs++){
        cin >> line;
        memset(byteArray,0,sizeof(byteArray));
        int pointer = 0 ;
        for(char c: line){
            if(c=='>'){
                pointer=(pointer+1)%100;
            }else if(c=='<'){
                pointer--;
                if(pointer<0)
                    pointer=99;
            }else if(c=='+'){
                byteArray[pointer]=(byteArray[pointer]+1)%256;
            }else if(c=='-'){
                byteArray[pointer]--;
                if(byteArray[pointer]<0)
                    byteArray[pointer]=255;
            }
        }
        printf("Case %d:",cs);
        for(int i = 0 ; i < 100 ; i ++){
            printf(" %02X",byteArray[i]);
        }
        printf("\n");
    }
    return 0;
}