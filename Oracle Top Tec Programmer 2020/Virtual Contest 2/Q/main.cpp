#include<bits/stdc++.h>

#define mod 1000000007
#define maxLength 90002
#define p 29

using namespace std ; 

string s ;
int64_t hashAcum [maxLength],pS[maxLength];
int64_t lim;

int64_t getValue(char x){
    if(x=='\0')
        return 1 ; 
    return x - 'a' + 2 ; 
}

void initializeHash(){
    hashAcum[0] = getValue(s[0]);
    pS[0]=1;
    for(int64_t i = 1 ; i < s.size() ; i ++ ){
        pS[i]=(pS[i-1]*p)%mod;
        hashAcum[i] = ((hashAcum[i-1]*p) % mod + getValue(s[i])) % mod;
    }
}

int64_t valStr(int64_t i , int64_t j ){// i - 1 
    if(i==0){
        return hashAcum[j];
    }
    //i > 0 
    return ((hashAcum[j] - (hashAcum[i-1] * pS[j-i+1]) % mod) + mod)%mod;
}

int64_t firstDif(int64_t i , int64_t j ){
    int64_t l = 0 , r = s.size() - 1 - max(i,j);
    while(l+1<r){
        int64_t mid = (l+r)/2;
        if(valStr(i,i+mid)==valStr(j,j+mid)){
            l = mid + 1 ;
        }else{
            r = mid ; 
        }
    }
    if(valStr(i,i+l)!=valStr(j,j+l)){
        return l ; 
    }
    return r ; 
}

bool comparison(int64_t i , int64_t j ){
    int64_t dif = firstDif(i,j);
    /*cout << "comparison s[i+dif]: " << s[i+dif] << " s[j+dif]: "<< s[j+dif] << "\n";
    cout << "i: " << i << " j: " << j << " dif: "<< dif << "\n";*/
    return s[i+dif] < s[j+dif];
}

int64_t prefixBeg[maxLength],acum[maxLength],firstIndex[maxLength];

void precalcRanges(){
    firstIndex[0]=prefixBeg[0];
    acum[0]=s.size()-1-firstIndex[0];
    for(int64_t i = 1 ; i < lim ; i ++ ){
        //cout << "firstDif[i]: " << firstDif(prefixBeg[i],prefixBeg[i-1]) << "\n";
        firstIndex[i]=prefixBeg[i]+firstDif(prefixBeg[i],prefixBeg[i-1]);
        acum[i]=acum[i-1]+s.size()-1-firstIndex[i];
    }
}

int64_t getRange(int64_t x){
    int64_t l = 0 , r = s.size()-2 ;
    while(l+1<r){
        int64_t mid = (l+r)/2;
        if(acum[mid]<x){
            l = mid ; 
        }else{
            r = mid ; 
        }
    } 
    if(acum[l]>=x){
        return l ; 
    }
    return r ; 
}

void print64_tSubstr(int64_t x){
    int64_t rangePos = getRange(x);
    //cout << "rangePos: " << rangePos << "\n";
    if(acum[rangePos]<x){
        x = acum[rangePos];
    }
    //normal
    int64_t dif = (rangePos ? x-acum[rangePos-1] : x)-1 ; 
    //cout << "dif: " << dif << "\n";
    cout << s.substr(prefixBeg[rangePos],firstIndex[rangePos]+dif-prefixBeg[rangePos]+1) <<  "\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> s ; 
    s.push_back('\0');
    lim = s.size()-1;
    initializeHash();
    for(int64_t i = 1 ; i < s.size() ; i ++ ){
        prefixBeg[i-1]=i-1;
    }
    sort(prefixBeg,prefixBeg+s.size()-1,comparison);
    /*cout << "sorted prefix begs\n";
    for(int64_t i = 0 ; i + 1 < s.size() ; i ++ ){
        cout << prefixBeg[i] << " " ; 
    }
    /*cout << "\n";
    cout << "valStrings\n";
    cout << valStr(0,0) << " " << valStr(1,1) << "\n";
    cout << "hashAcum:\n";
    for(int64_t i = 0 ; i < s.size() ; i ++ ){
        cout << hashAcum[i] << " " ;  
    }*/
    //cout << "\n";
    precalcRanges();
    /*for(int64_t i = 0 ; i < lim ; i ++ ){
        cout << "acum[i]: " << acum[i] << "prefixBeg[i]: " << prefixBeg[i] << "firstIndex[i]: " << firstIndex[i] << "\n"; 
    }*/
    int64_t q,k; 
    cin >> q ; 
    while(q--){
        cin >> k ; 
        print64_tSubstr(k);
    }
    return 0;
}