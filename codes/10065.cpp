#include<cstdio>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

struct point {
public:
    double x, y;
    point() {}
    point(double x, double y): x(x), y(y) {}
};

int turn(point p, point q, point r){
    int result = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
    if(result < 0) return -1; //p->q->r horario
    if(result > 0) return 1; //sentido anti horario
    return 0; //colineares
}

bool ccw(point p, point q, point r){ return (turn(p,q,r) > 0);}
// >=0 aceita colineares

point pivot;
vector<point> polygon, CH;
double ap;

int area2(point a, point b, point c){
    return a.x*b.y - a.y*b.x + b.x*c.y - b.y*c.x + c.x*a.y - c.y*a.x;
}

int dist2(point a, point b){
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx*dx + dy*dy;
}

bool angle_cmp(point a, point b){
    if(area2(pivot,a,b) == 0) //colinear
        return dist2(pivot,a) < dist2(pivot,b); //mais perto

    int d1x = a.x-pivot.x, d1y = a.y - pivot.y;
    int d2x = b.x-pivot.x, d2y = b.y - pivot.y;
    return (atan2((double)d1y,(double)d1x) - atan2((double)d2y,(double)d2x)) < 0;
}

double poly_area(vector<point> &T){
    double s=0; int n=T.size();
     for(int i=0; i<n; i++){      
         s += T[i].x * T[(i+1)%n].y - T[i].y * T[(i+1)%n].x;
     }
     return s/2;
}

vector<point> GrahamScan(vector<point> Polygon){
    int i, PO = 0, N = Polygon.size();
    for(int i = 1; i < N; i++)
        if(Polygon[i].y < Polygon[PO].y || (Polygon[i].y == Polygon[PO].y && Polygon[i].x > Polygon[PO].x))
            PO = i;

    point temp = Polygon[0];
    Polygon[0] = Polygon[PO];
    Polygon[PO] = temp;

    pivot = Polygon[0];
    sort(++Polygon.begin(),Polygon.end(),angle_cmp);

    stack<point> S;
    point prev, now;
    S.push(Polygon[N-1]);
    S.push(Polygon[0]);

    i=1;
    while(i<N){ //N >= 3
        now = S.top(); S.pop();
        prev = S.top(); S.push(now);
        if(ccw(prev,now,Polygon[i])){
            S.push(Polygon[i]);
            i++;
        }
        else
            S.pop();
    }

    vector<point> ConvexHull;
    while(!S.empty()){
        ConvexHull.push_back(S.top());
        S.pop();
    }
    ConvexHull.pop_back(); //ultimo é copia do primeiro

    return ConvexHull;
}


int main(){
    int n,t=1;
	while(scanf("%d",&n) &&  n){
		printf("Tile #%d\n",t++);
		
		vector<point> T;
		while(n--){
			double x,y;
			scanf("%lf %lf",&x,&y);
			T.push_back(point(x,y));
		}
        ap = poly_area(T);
		
		vector<point> P = GrahamScan(T);
		double ac = poly_area(P);
		
        printf("Wasted Space = %.2lf %%\n",100-100*fabs((ap/ac)));
		printf("\n");
	}
    return 0;
}
