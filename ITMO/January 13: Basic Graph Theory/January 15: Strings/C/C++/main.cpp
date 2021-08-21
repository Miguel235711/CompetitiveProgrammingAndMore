#include<bits/stdc++.h>
#define p0 257
#define maxL 100008
#define mod 1000000009
 
using namespace std;
 
int p[maxL],h[maxL],n;
string s ;
 
void calcPs(){
    p[0]=1;
    for(int i = 1 ; i < n ; i++)
        p[i]=(int64_t)p[i-1]*p0%mod;
}
 
int a,b,c,d ; 
 
int f(int i,int j){///inclusive
    return ((h[j]-(int64_t)h[i-1]*p[j-i+1]%mod)+mod)%mod;
}
 
bool same(){
    return f(a,b)==f(c,d);
}
 
void calcHash(){
    h[0]=s[0];
    for(int i = 1 ; i < n ; i++)
        h[i] = ((int64_t)h[i-1]*p0%mod + s[i])%mod;
    
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> s ; 
    n = s.size();
    calcPs();
    calcHash();
    int m;
    cin >> m ; 
    while(m--){
        cin>>a>>b>>c>>d;
        a--,b--,c--,d--;
        cout << (b-a==d-c&&same()?"Yes":"No") << "\n";
    }
    return 0;
}