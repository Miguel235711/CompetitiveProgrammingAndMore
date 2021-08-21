//brute force
/*#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int l,d,v,g,r;
    cin >> l>>d>>v>>g>>r;
    double ti = (double)d/v,extra=0;
    for(int i = 0 ; ;i++){
        if(i*(g+r)<=ti&&ti<i*(g+r)+g){
            //green
            cout << "i: " << i << "\n";
            break;
        }else if(i*(g+r)+g<=ti&&ti<(1+i)*(g+r)){
            //red, wait
            extra = (1+i)*(g+r) - ti;
            cout << "i: " << i << "\n";
            break;
        }
    }
    cout << fixed << setprecision(8) << (double)l/v+extra <<"\n" ; 
    return 0;
}*/
/*#include<bits/stdc++.h>

using namespace std;

int l,d,v,g,r;
double ti;

int binSearch(int ll,int rr){
    while(ll+1<rr){
        int mid = (ll+rr)/2;
        if(mid*(g+r)>ti)
            rr = mid - 1;
        else if((mid+1)*(g+r)<=ti)
            ll = mid + 1 ;
        else{
            return mid;
        }  
    }
    if(ll*(g+r)<=ti&&ti<(ll+1)*(g+r))
        return ll;
    return rr;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> l>>d>>v>>g>>r;
    ti = (double)d/v;
    double extra=0;
    int ll = 0 , rr =ceil((double)d/v*(g+r) - 1);
    int i = binSearch(ll,rr);
    if(i*(g+r)+g<=ti&&ti<(1+i)*(g+r)){
        //red, wait
        extra = (1+i)*(g+r) - ti;
    }//otherwise, green don't do anything
    cout << fixed << setprecision(8) << (double)l/v+extra <<"\n" ; 
    return 0;
}*/
//formula
#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int l,d,v,g,r;
    cin >> l>>d>>v>>g>>r;
    double ti = (double)d/v,extra=0;
    int i = ti/(g+r);
    if(i*(g+r)+g<=ti){
        //red, wait
        extra = (1+i)*(g+r) - ti;
    }
    cout << fixed << setprecision(8) << (double)l/v+extra <<"\n" ; 
    return 0;
}