#include<vector>
#include<map>
#include<iostream>
#include<cstring>

using namespace std;

///operators overloading

const int lim = 100008;

int bits[2][lim],a[lim],n,k,A,B;
char c;

int magic(int x){
    return x&-x;
}

void update(int b,int x,int p){
    for(;p<=n;p+=magic(p))
        bits[b][p]+=x;
}

int q(int b,int p){
    int ans = 0;
    for(;p;p-=magic(p))
        ans+=bits[b][p];
    return ans;
}

int query(int b,int l,int r){
    return q(b,r) - q(b,l-1);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>n>>k){
        memset(bits,0,sizeof(bits));
        for(int i = 1 ; i <= n ; i ++){
            cin >> a[i];
            if(a[i]==0)
                update(0,1,i);
            else if(a[i]<0)
                update(1,1,i);
        }
        while(k--){
            cin >> c >> A >> B; 
            if(c=='C'){
                if(a[A]==0)
                    update(0,-1,A);
                else if(a[A]<0)
                    update(1,-1,A);
                //update
                a[A]=B;
                if(B==0)
                    update(0,1,A);
                else if(B<0)
                    update(1,1,A);
            }else
                cout << (query(0,A,B)?'0':(query(1,A,B)&1 ? '-':'+'));
        }
        cout << "\n";
    }
    return 0;
}