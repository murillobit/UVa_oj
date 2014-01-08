//OK!
#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define EACH(i,c) for(__typeof((c).begin()) i = (c).begin(); i !=c.end(); ++i)

using namespace std;

typedef int Weight;

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

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void MST(const Graph &g) {
	int n = g.size();
	UnionFind uf(n);
	priority_queue<Edge> Q;
	REP(u,n) EACH(e,g[u])  Q.push(*e);

	Weight total = 0;
	Edges cycleEdges;
	while (!Q.empty()) {
		Edge e = Q.top(); Q.pop();
		if(!uf.unionSet(e.src,e.dst)){
			cycleEdges.push_back(e);
		}
	}
	int i;
	for(i = 0; i < cycleEdges.size(); i++){
	    Edge e = cycleEdges[i];
	    cout << e.weight << ((i==cycleEdges.size()-1)? "\n" : " ");
	}
	if(!i) cout << "forest\n";
}

int main(){
	int m,n;
	while(scanf("%d %d",&m,&n) && (m||n)){
		Graph G(m);
		int totalWeight=0;
		REP(i,n){
			int s,d,w;
			scanf("%d %d %d",&s,&d,&w);
			G[s].push_back(Edge(s,d,w));
			totalWeight += w;
		}
		MST(G);
	}
	return 0;
}
