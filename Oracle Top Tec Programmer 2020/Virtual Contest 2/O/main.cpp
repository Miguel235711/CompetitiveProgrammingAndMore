#include<bits/stdc++.h>

using namespace std ; 

struct point {
	int x , y ;
    point operator - (point const & other)const{
        return point(x-other.x,y-other.y);
    } 
    point(){}
    point(int x, int y){
        this->x=x;
        this->y=y;
    }
};

int n,q;

point points[1002];

int64_t dotProduct ( point a , point b ) {
	return  (int64_t)a.x * b.y - (int64_t)a.y * b.x;
}

bool isLeft(point orig, point dest, point toAsk){
    return dotProduct(dest-orig,toAsk-orig) > 0 ; 
}
bool isRight(point orig, point dest, point toAsk){
    return dotProduct(dest-orig,toAsk-orig) < 0 ; 
}

point orig;

int binSearch(int x,int y){
    int l = 1 , r = n - 1 ; 
    //cout << "orign -> x:" << orig.x << " y: " << orig.y << "\n";
    while(l+1<r){
        int mid = (l+r)/2;
        if(isLeft(orig,points[mid],point(x,y))){
            l = mid ; 
        }else{
            r = mid ; 
        }
    }
    return l ; 
}

bool insideTriangle(point orig,point b,point c,int x , int y){
    point toAsk = point(x,y);
    return !isRight(orig,b,toAsk) && !isRight(b,c,toAsk) && !isRight(c,orig,toAsk);
}

void calc(int x, int y ){
    int begOfTriangle=binSearch(x,y);
    //cout << "begOfTriangle: " << begOfTriangle << "\n";
    if(insideTriangle(orig,points[begOfTriangle],points[begOfTriangle+1],x,y)){
        cout << "D";
    }else{
        cout << "F";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q ;
    cin >> orig.x >> orig.y;
    for(int i = 1 ; i < n ; i ++ ){
        cin >> points[i].x >> points[i].y;
    }
    int x , y ; 
    while(q--){
        cin >> x >> y ; 
        calc(x,y);
    }
    return 0;
}