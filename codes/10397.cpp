//OK!
#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
#include<cstring>
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define EACH(i,c) for(__typeof((c).begin()) i = (c).begin(); i !=c.end(); ++i)

using namespace std;

typedef double Weight;
typedef pair<int,int> Point;
int adj[755][755];

struct UnionFind{
	vector<int> data;
	UnionFind(int size) : data(size,-1) {}
	bool unionSet(int x, int y){
		x = root(x); y = root(y);
		if(x!=y){
			if(data[y] < data[x]) swap(x,y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y){
		return root(x) == root(y);
	}
	int root(int x){
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
};

struct Edge{
	int src, dst;
	Weight weight;
	Edge(int src, int dst, Weight weight):
		src(src), dst(dst), weight(weight) {}
};

bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : e.src != e.src ? e.src < f.src : e.dst < f.dst;
}

double dist(double x1, double y1, double x2, double y2){
    //printf("%lf %lf %lf %lf\n",x1,y1,x2,y2);
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

Weight MST(const Graph &g, vector< Point > p) {
	int n = g.size();
	UnionFind uf(n);
	priority_queue<Edge> Q;
	REP(u,n) EACH(e,g[u]) Q.push(*e);
	
	Weight total = 0;
	Edges F;
	while (F.size() < (n-1) && !Q.empty()) {
	    Edge e = Q.top(); Q.pop();
		if(uf.unionSet(e.src,e.dst)){
			F.push_back(e);
			//total += e.weight;
			//printf("1) %d %d %lf\n",e.src,e.dst,e.weight);
		}
	}
	if(F.size() < (n-1)){
	    REP(i,n){
            REP(j,n){
                if(uf.findSet(i,j)){
                    adj[i][j] = adj[j][i] = 1;
                }
                if(adj[i][j] == 0){//
                    int x1,x2,y1,y2;
                    double w;
			        x1 = p[i].first;
			        y1 = p[i].second;
			        x2 = p[j].first;
			        y2 = p[j].second;
			        w = dist(x1,y1,x2,y2);
			        Q.push(Edge(i,j,w));
                    adj[i][j] = adj[j][i] = 1;
                }
            }
	    }
	}
	while (F.size() < (n-1) && !Q.empty()) {
		Edge e = Q.top(); Q.pop();
		if(uf.unionSet(e.src,e.dst)){
			F.push_back(e);
			total += e.weight;
			//printf("2) %d %d %lf\n",e.src,e.dst,e.weight);
		}
	}
	return total;
}

int main(){
	while(!feof(stdin)){
	    int n,m;
	    scanf("%d\n",&n);
		Graph G(n);
		vector< Point > points;

		memset(adj,0,sizeof(adj));
		
		REP(i,n){
		    int x,y;
		    scanf("%d %d\n",&x,&y);
		    points.push_back(make_pair(x,y));
		}
		
		scanf("%d\n",&m);
		REP(i,m){
			int s,d;
			double w;
			scanf("%d %d\n",&s,&d);
			s--; d--;
			int x1,x2,y1,y2;
			x1 = points[s].first;
			y1 = points[s].second;
			x2 = points[d].first;
			y2 = points[d].second;
			w = dist(x1,y1,x2,y2);
			//printf("%d %d %lf\n",s,d,w);
			G[s].push_back(Edge(s,d,w));
			adj[s][d] = adj[d][s] = 1;
		}
		printf("%.2lf\n",MST(G,points));
	}
	return 0;
}
