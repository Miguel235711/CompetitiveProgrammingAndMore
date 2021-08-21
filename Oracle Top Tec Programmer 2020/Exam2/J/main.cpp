#include<bits/stdc++.h>

#define maxQuantums 1000
#define maxSz 500002

using namespace std;

int64_t n,quantumSize ; 
int64_t mini[maxQuantums],maxi[maxQuantums],bestAns[maxQuantums];
int64_t arr[maxSz],acum[maxSz];

int64_t getQuantum(int64_t pos){
    return pos / quantumSize ;
}

void precalculate(){
    for(int64_t begQuantum = 0, quantum=0 ; begQuantum < n ; begQuantum += quantumSize,quantum++ ){
        int64_t lim = min(begQuantum + quantumSize,n);
        //cout << "lim: " << acum[lim-1] << " quantum: " << quantum << "\n";
        mini[quantum] = begQuantum?acum[begQuantum-1]:0;
        maxi[quantum] = acum[begQuantum]; 
        bestAns[quantum] = arr[begQuantum] ;
        for(int64_t j = begQuantum + 1 ; j < lim ; j++ ){
            bestAns[quantum]=max(bestAns[quantum],acum[j] - mini[quantum]);
            mini[quantum] = min(mini[quantum],acum[j]);
            maxi[quantum] = max(maxi[quantum],acum[j]);
        }
    }
}

int64_t bruteQuery(int64_t p,int64_t lim,int64_t & minLocal, int64_t & maxLocal){
    minLocal = min(acum[p],p?acum[p-1]:0);
    //cout << "before: " << (p?acum[p-1]:0)<< "\n";
    int64_t greatest = acum[p]-(p?acum[p-1]:0);
    maxLocal = acum[p];
    //cout << "maxLocal: " << maxLocal << "\n";
    p++;
    for(;p<lim;p++){
        //cout << "entered:\n";
        greatest = max(greatest,acum[p]-minLocal);
        minLocal = min(minLocal,acum[p]);
        maxLocal = max(maxLocal,acum[p]);
    }
    //cout << "greatest: " << greatest << "\n";
    return greatest;
}

int64_t query(int64_t l,int64_t r){
    int64_t qL = getQuantum(l),qR = getQuantum(r);
    int64_t greatestAns = LLONG_MIN;
    //calculate partial local
    int64_t maxLocalL,minLocalL;
    int64_t maxLocalR,minLocalR;
    greatestAns = max(greatestAns,bruteQuery(l,min((qL+1)*quantumSize,r+1),minLocalL,maxLocalL)); //[init , lim)
    greatestAns = max(greatestAns,bruteQuery(max(qR*quantumSize,l),r+1,minLocalR,maxLocalR));
    //cout <<  mini[0] << "\n";
    //cout << "maxi: " << maxi[1] << "\n";
    //cout << "minLocalL: " << minLocalL << "\n";
    //cout << "l: " << l << " r: " << r  << "qL: " << getQuantum(l) << " qR: " << getQuantum(r) << "\n";
    if(qL+1<qR){
        //no brute force
        for(int64_t quant = qL + 1 ; quant < qR ; quant++){
            greatestAns = max(greatestAns,bestAns[quant]);
        }
        //calculate sub
        int64_t minimum = minLocalL;
        for(int64_t quant = qL + 1 ; quant < qR ; quant ++){
            greatestAns = max(greatestAns,maxi[quant]-minimum);
            minimum = min(minimum,mini[quant]);
        }
        //cout << "maxLocalR: " << maxLocalR << "\n";
        greatestAns = max(greatestAns,maxLocalR-minimum);
    }else if(l!=r){
        greatestAns = max(greatestAns,maxLocalR-minLocalL);
    }
    return greatestAns;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ; 
    for(int64_t i = 0 ; i < n ; i ++){
        cin >> arr[i];
        //cout << "arr[i]: " << arr[i] << "\n";
        acum[i]=arr[i];
        if(i!=0){
            acum[i]+=acum[i-1];
        }
        //cout << "acum: " << acum[i]<< "\n" ;
    }
    quantumSize = sqrt(n);
    precalculate();
    int64_t m;
    cin >> m ; 
    //cout << "m: " << m << "\n";
    while(m--){
        int64_t xi,yi;
        cin >> xi >> yi;
        //cout << "xi: " << xi << " yi: " << yi << "\n";
        xi--;
        yi--;
        cout << query(xi,yi) << "\n";
    }
    return 0;
}