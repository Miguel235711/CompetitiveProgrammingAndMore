#include<bits/stdc++.h>
using namespace std;

#define m 1000000007



int64_t exp(int64_t base,int64_t power){
    if(!power) return 1 ;
    int64_t x = exp(base,power/2);
    x=(x*x)%m;
    if(power&1) 
        x=(x*base)%m;
    return x ;
}

int64_t division(int64_t a , int64_t b ){
    return((a%m)*(exp(b,m-2)%m))%m;
}

void
test_case(int num)
{
    long long int N, K;
    cin >> N >> K;
    long long ans;
    ans = K+1;
    ans *= N+1;
    ans = ans%m;
    ans *= (N+2);
    ans = ans%m;
    ans  = division(ans,2);    
    cout << ans << '\n';
}

int
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	/* main */
    int cases;

    cin >> cases;
    for (int i = 0; i < cases; i++) {
	    test_case(i);
    }

    return 0;
}
