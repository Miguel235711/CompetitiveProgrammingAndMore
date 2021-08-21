#include<bits/stdc++.h>
#define mod 1000000007 
#define init {{1,1},{1,0}}

using namespace std ; 



int64_t a[2][2]=init,b[2][2]=init,c[2][2]=init,d[2][2]=init,aux[2][2],single[2][2]=init,baseCases[2][1]={{1},{0}};

void multiply(int64_t *a,int64_t *b){
    int64_t rowsA =  sizeof(a) / sizeof(a[0]) + 1 ;
    int64_t colsB = sizeof(b[0]) / sizeof(int64_t) + 1 ;//tricky
    int64_t rowsB = sizeof(b) / sizeof(b[0]) + 1;
    //cout << rowsA << " " << colsB << " " << rowsB << "\n";
    for(int64_t i = 0 ; i < rowsA ; i ++){
        for(int64_t c = 0 ; c < colsB ; c ++){
            for(int64_t r = 0 ; r < rowsB ; r++ ){
                aux[i][c] += (*((a+i*colsB)+r) * *((b+r*colsB)+c))%mod;
                aux[i][c] %= mod;
            }
        }
    }
    for(int64_t i = 0 ; i < rowsA ; i ++){
        for(int64_t j = 0 ; j < colsB ; j ++){
            *((a+i*colsB)+j) = aux[i][j];
            aux[i][j]=0;
        }
    }
}

void expMatrix(int64_t * matrix,int64_t exp){
    if(exp<=1)
        return;
    expMatrix(matrix,exp/2);
    multiply(matrix,matrix);
    if(exp&1)
        multiply(matrix,(int64_t *)single);
}

int64_t calculateFibo(int64_t x ,int64_t * matrix){
    expMatrix((int64_t *)matrix,x-1);
    if(x<=0){
        memset(matrix,0,sizeof(matrix));
    }
    multiply((int64_t*)matrix,(int64_t *)baseCases);
    return *matrix;
}

int64_t calculateFiboAcum(int64_t x,int64_t * a , int64_t * b){
    int64_t fibo = calculateFibo(x,a);
    int64_t fiboMinus1 = calculateFibo(x-1,b);
    return !fibo ? 0 : (fibo*2%mod+fiboMinus1-1+mod)%mod;
}

int64_t n,m ; 

void initialize(int64_t * a){
    int64_t rowsA =  sizeof(a) / sizeof(a[0]) + 1 ;
    int64_t colsA = sizeof(a[0]) / sizeof(int64_t) + 1 ;//tricky
    for(int64_t i = 0 ; i < rowsA ; i ++ ){
        for(int64_t j = 0 ; j < colsA ; j ++){
            *((a+i*colsA)+j) = single[i][j];
        }
    }
}

void initializeAll(){
    initialize((int64_t *)a);
    initialize((int64_t *)b);
    initialize((int64_t *)c);
    initialize((int64_t *)d);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int64_t t ;
    cin >> t ; 
    while(t--){
        initializeAll();
        cin >> n >> m ;
        cout << ( calculateFiboAcum(m,(int64_t *)a,(int64_t *)b) - calculateFiboAcum(n-1,(int64_t *)c,(int64_t *)d) + mod ) % mod << "\n";
    }
    return 0;
}   