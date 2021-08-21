#include<bits/stdc++.h>

#define limN 100008
#define m 1000000007

int64_t factPrec[100008];

void precalc(){
    factPrec[0]=1;
    for(int i = 1 ; i < limN; i ++){
        factPrec[i]=factPrec[i-1]*i;
        factPrec[i]%=m;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    precalc();
    return 0;
}