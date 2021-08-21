#include<bits/stdc++.h>

using namespace std;

double f(double x){
    return x*x + sqrt(x);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    double c ;
    cin >> c;
    double l = 1 , r = 1e5, precision = 1e-7, answer = 0;
    //cout << "precision: " << precision << "r: " << r << "\n";
    while( l+precision < r){
        double mid = (l + r) / 2 ;
        double fV = f(mid);
        if(fV==c)
            answer = mid;
        if(fV<c)
            l = mid + precision;
        else
            r = mid - precision;
    }
    if(answer==0)
        answer = f(l) == c ? l : r;
    cout << fixed << setprecision(6) << answer << "\n";
    return 0;
}