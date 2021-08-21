#include<bits/stdc++.h>

using namespace std;

int difPositions(int orig, int dest, bool clockwise){
    if(clockwise){
        swap(orig,dest);
    }
    return dest<=orig ? orig - dest : 40 - dest + orig ; // ternary expression
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int init, a, b, c;
    while(cin>>init>>a>>b>>c,init||a||b||c){
        cout << (difPositions(init,a,false) + difPositions(a,b,true) + difPositions(b,c,false)) *9 + 1080 << "\n";
    }
    return 0;
}