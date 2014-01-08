#include<cstdio>
#include<cmath>
#define EPS 1e-9

using namespace std;

struct point{
    double x,y;
    point() {x = y = 0.0;}
    point(double _x, double _y): x(_x), y(_y) {}
};

struct vec{ double x,y;
    vec(double _x, double _y):x(_x),y(_y) {}
};

vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s){
    return vec(v.x * s, v.y *s);
}

point translate(point p, vec v){
    return point(p.x + v.x, p.y + v.y);
}

double cross(vec a, vec b){
    return a.x * b.y - a.y * b.x;
}

double xa,ya,xb,yb,xc,yc,xd,yd,xe,ye,xf,yf,a_def,a_abc,s;

int main(){
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",&xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd,&xe,&ye,&xf,&yf) && (xa>=EPS||ya>=EPS||xb>=EPS||yb>=EPS||xc>=EPS||yc>=EPS||xd>=EPS||yd>=EPS||xe>=EPS||ye>=EPS||xf>=EPS||yf>=EPS)){
        point a(xa,ya), b(xb,yb), c(xc,yc), d(xd,yd), e(xe,ye), f(xf,yf);
        vec ab = toVec(a,b);
        vec ac = toVec(a,c);
        vec de = toVec(d,e);
        vec df = toVec(d,f);
        a_def = fabs(cross(de,df))/2.0;
        a_abc = fabs(cross(ab,ac));
        s = a_def/a_abc;
        vec ah = scale(ac,s);
        point h = translate(a,ah);
        point g = translate(b,ah);
        printf("%.3lf %.3lf %.3lf %.3lf\n",g.x,g.y,h.x,h.y);
    }
    return 0;
}
