#include<bits/stdc++.h>

#define pi 3.141592653589793

using namespace std;

double dist(double x1,double x2,double y1,double y2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

double calcC5(double x1,double x2){
    return 2*(x2-x1);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    pair<double,double> c[3];
    while(cin >> c[0].first >> c[0].second){
        for(int i = 1 ; i < 3 ; i ++)
            cin >> c[i].first >> c[i].second;
        sort(c,c+3);
        double c5=0;
        do{
            c5=calcC5(c[0].first,c[1].first);
        }while(!c5&&next_permutation(c,c+3));
        double c1=pow(c[2].first,2)-pow(c[1].second,2)+pow(c[2].second,2)-pow(c[1].first,2),
        c2=2*(-c[2].first+c[1].first),c3=2*(-c[1].second+c[2].second),c4Prime=-pow(c[0].first,2)+pow(c[1].first,2),c4=+c4Prime+pow(c[1].second,2)-pow(c[0].second,2),c6=2*(-c[1].second+c[0].second);
        double y = (c5*c1+c2*c4)/(c5*c3-c2*c6);
        double x = (pow(c[1].second-y,2)-pow(c[0].second-y,2)+c4Prime)/c5;
        cout << fixed << setprecision(2) << dist(x,c[0].first,y,c[0].second) * pi * 2 <<  "\n";        
    }
    return 0;
}