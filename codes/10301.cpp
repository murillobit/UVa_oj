//OK
#include<cstdio>
#include<vector>
#include<cmath>
#include<iostream>

using namespace std;

struct UnionFind{
    vector<int> id,sz;
    UnionFind(int n): id(n), sz(n,1) {for (int i = 0; i < id.size(); i++) id[i] = i;}
    int root(int i){
        while(i != id[i]) i = id[i];
        return i;
    }
    int unionUF(int p, int q){
        int i = root(p);
        int j = root(q);
        if(i!=j){
            if(sz[i] < sz[j]) {
                id[i] = j;
                sz[j] += sz[i];
                return sz[j];
            }
            else {
                id[j] = i;
                sz[i] += sz[j];
                return sz[i];
            }
        }
        else return sz[i];
    }
};

struct point{
    double x,y,r;
    point(){}
    point(double X, double Y, double R): x(X), y(Y), r(R) {}
    bool intersect(point p){
        double dist = sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
        if(x==p.x && y==p.y && r==p.r) return true;
        return (dist < (r+p.r)) && (dist > fabs(r-p.r));
    }
};

int main(){
    int n;
    while(scanf("%d",&n) && (n>=0)){
        vector<point> points;
        UnionFind UF(n);
        int maxsize = n? 1:0;
        for(int i = 0; i < n; i++){
            double x,y,r;
            scanf("%lf%lf%lf",&x,&y,&r);
            points.push_back(point(x,y,r));
            for(int j = 0; j < i; j++){
                if(points[i].intersect(points[j])){
                    maxsize = max(maxsize,UF.unionUF(i,j));
                }
            }
        }
        if(maxsize==1) printf("The largest component contains %d ring.\n",maxsize);
        else printf("The largest component contains %d rings.\n",maxsize);
    }
    return 0;
}
