#include<bits/stdc++.h>

#define m 1000000007
#define length 1000002
#define lim 1000000

using namespace std ;

int64_t exp(int64_t base,int64_t power){
    if(!power) return 1 ;
    int64_t x = exp(base,power/2);
    x=(x*x)%m;
    if(power&1) x=(x*base)%m;
    return x ;
}

int64_t division(int64_t a , int64_t b ){
    ///return (a%m)/(b%m)
    return((a%m)*(exp(b,m-2)%m))%m;
}

int64_t factorial[length];
void initFact(){
    factorial[0]=1;
    for(int64_t i = 1 ; i <= lim ; i ++){
        factorial[i]=((int64_t)factorial[i-1]*i)%m;
    }
}

int64_t N,A,B,D;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    initFact();
    while(cin>>N>>A>>B>>D){
        int64_t school = division(factorial[N],(factorial[N-A]*factorial[A])%m);
        int64_t students = division(factorial[B],(factorial[B-D]*factorial[D])%m);
        int64_t expStudents = exp(students,A);
        cout <<  (school * expStudents)%m << "\n" ; 
    }
    return 0;
}