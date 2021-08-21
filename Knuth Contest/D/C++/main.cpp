#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007

int64_t exp(int64_t base, int64_t power){
    if(!power)
        return 1;
    int64_t x = exp(base,power/2);
    x = (x*x)%mod;
    if(power&1)
        x=(x*base)%mod;
    return x;
}

int64_t division(int64_t a, int64_t b){
    return ((a%mod)*(exp(b,mod-2)%mod))%mod;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int64_t n,sum=0;
    cin >> n;
    /*for(int64_t i = 1 ;n;i++){
        if(n-i*2>=0){
            sum+=(i*i)%mod*2%mod;
            n-=i*2;
        }else{
            sum+=(i*n)%mod,n=0;
        }
        sum%=mod;
    }*/
    int64_t l = 0 , r = 1e9;
    while(l+1<r){
        int64_t mid = (l+r)/2;
        if(mid*(mid+1)>n)
            r = mid -1 ; 
        else
            l = mid;
    }
    //cout << "l: " << l << " r: " << r << "\n";
    int64_t chosenK = 0;
    if(r*(r+1)<=n){
        chosenK = r;
    }else{
        chosenK = l;
    }
    n -= chosenK*(chosenK+1);
    sum+=chosenK*(chosenK+1)%mod*(2*chosenK+1)%mod;
    sum=division(sum,3);
    sum+=(chosenK+1)*n%mod;
    sum%=mod;
    cout << sum << "\n";
    return 0;
}