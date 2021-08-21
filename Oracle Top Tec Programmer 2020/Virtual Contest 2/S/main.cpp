#include<bits/stdc++.h>

using namespace std ; 

int64_t n , b ; 
vector< pair<int64_t,int> > bFactorization;

void insertIfPrime(int64_t x){
    int lim = sqrt(x);
    for(int i = 2 ; i <= lim ; i ++){
        if(x % i == 0 ){ //no prime
            return ;
        }
    }
    //x is prime, insert the necessary times
    int exponent = 0 ;
    //cout << "x: " << x << "\n";
    for(int64_t tempB = b ; tempB%x==0;tempB /= x){
        //cout << "entered\n";
        exponent ++;
    }
    bFactorization.push_back(make_pair(x,exponent));
}

void factorizeB(){//O(sqrt(b)*log(b)
    int lim = sqrt(b);
    for(int i = 2 ; i <= lim ; i ++ ){
        if(b % i  == 0 ){
            insertIfPrime(i);
            if(b/i != i ){
                insertIfPrime(b/i);
            }
        }
    }
    insertIfPrime(b);
}

void countAppearences(){
    int64_t minimum = LLONG_MAX;
    for(const auto & factorB: bFactorization){
        int64_t prime = factorB.first ; 
        int64_t amount = 0 ; 
        while(1) {
            amount += n / prime ; 
            if(n/prime<factorB.first)break;
            prime *= factorB.first ;
        }
        minimum = min(minimum , amount / factorB.second );
    }
    cout << minimum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> b ; 
    factorizeB();
    countAppearences();
    return 0;
}