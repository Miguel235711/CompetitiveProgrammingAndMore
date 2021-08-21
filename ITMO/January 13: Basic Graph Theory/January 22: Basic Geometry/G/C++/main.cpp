#include <bits/stdc++.h>

using namespace std;

struct point{
    double x,y;
    point(double x,double y):x(x),y(y){}
    point(){}
    point operator-(point o)const{
        return point(x-o.x,y-o.y);
    }
    point& operator-=(point o){
        x-=o.x,y-=o.y;
        return *this;
    }
    double cross(point o){
        return x*o.y - y*o.x;
    }
    double dot(point o){
        return x*o.x + y*o.y;
    }
    double angle(point o){
        return atan2(cross(o),dot(o));
    }
    double len(){
        return sqrt(x*x+y*y);
    }
    double distance(point o){
        return (o-*this).len();
    }
    double triangleArea(point o1,point o2){
        o1-=*this,o2-=*this;
        return abs(o1.cross(o2))/2;
    }
};

double polyArea(vector<point> & poly){
    double area=0;
    for(size_t i = 0; i < poly.size(); ++i){
        area += poly[i].cross(poly[(i+1)%poly.size()]);
    }
    return abs(area) / 2;
}

struct line{
    double a,b,c;
    line(){}
    line(point p1,point p2){
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = -(a*p1.x+b*p1.y);
    }
    line(double a,double b, double c):a(a),b(b),c(c){}
    double dist(point p){
        return abs((p.x * a + p.y * b + c) / sqrt(a*a+b*b));
    }
};

bool are_parallel(line l1,line l2){
    return abs(l1.a * l2.b - l1.b * l2.a) < 1e-9;
}

point intersection(line l1, line l2){
    double d = l1.a * l2.b - l1.b * l2.a;
    double d1 = -l1.c * l2.b + l1.b * l2.c;
    double d2 = -l1.a * l2.c + l1.c * l2.a;
    return point(d1/d,d2/d);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    point p ;
    cin >> n ; 
    vector<point> points;
    bool negative=false, positive = false;
    for(int i = 0 ; i < n ; i ++)
        cin >> p.x >> p.y, points.push_back(p);
    for(int i = 0 ; i < n ; i ++){
        auto p1 = points[i?i-1:n-1]-points[i] , p2 = points[(i+1)%n]-points[i];
        if(p1.angle(p2)>0)
            positive = true;
        else
            negative = true;
        
    }
    cout << (positive&&negative ? "NO":"YES") << "\n";
    return 0 ; 
}