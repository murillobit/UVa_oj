#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
#define INF 2000000000
#define MAX_V 2005

using namespace std;

int res[MAX_V][MAX_V], mf, f, s, t;
vector<int> p;

void augment(int v, int minEdge){
    if(v==s){
        f=minEdge;
        return;
    }
    else if(p[v] != -1){
        augment(p[v],min(minEdge,res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int maxFlow(vector<int> *AdjL){
    mf = 0;
    while(true){
        f=0;
        queue<int> q;
        vector<int> dist(MAX_V,INF);
        q.push(s);
        dist[s] = 0;
        p.assign(MAX_V,-1);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u==t) break;
            for(int i=0; i<AdjL[u].size(); i++){
    	    	int v = AdjL[u][i];
                if(res[u][v] > 0 && dist[v] == INF){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    p[v] = u;
                }
            }
        }
        augment(t,INF);
        if(f==0) break;
        mf += f;
    }
    return mf;
}

set<int> vertexCover(vector<int> *AdjL, int n, int m){
    //n e o numero de vertices na particao 'L' da esquerda e m o numero de vertices na particao 'R' da direita
    set<int> T,VC;
    queue<int> Q;
    for(int i=1; i<=n; i++){
        if(res[i][0] == 0){//adiciona os vertices de 'L' que nao pertencem ao matching no conjunto T
            Q.push(i);
            T.insert(i);
        }
    }
    while(!Q.empty()){//faz um bfs para percorrer todos "alternating paths" a partir do conjunto T inicial
        int u = Q.front(); Q.pop();
        for(int i=0; i<AdjL[u].size(); i++){
            int v = AdjL[u][i];
            if(v!=0 && v!=(n+m+1) && res[u][v] > 0 && T.count(v) == 0){//so pega arestas que nao sao do matching de L->R e que sao do matching de R->L
                Q.push(v);
                T.insert(v);
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(T.count(i) == 0) VC.insert(i);//os vertices de L que nao pertencem a T pertencem ao vertex cover
    }
    for(int i=1; i<=m; i++){
        if(T.count(n+i) > 0) VC.insert(n+i);//os vertices de R que pertencem a T pertencem ao vertex cover
    }
    return VC;
}

int main(){
	int r,c,n;
	while(scanf("%d %d %d",&r,&c,&n) && (r||c||n)){
		memset(res,0,sizeof(res));
        vector<int> AdjL[r+c+2];
        
        for(int i=0; i<r; i++) {res[0][i+1] = 1; AdjL[0].push_back(i+1); AdjL[i+1].push_back(0);}
        for(int i=0; i<c; i++){res[r+i+1][r+c+1] = 1; AdjL[r+i+1].push_back(r+c+1); AdjL[r+c+1].push_back(r+i+1);}

		for(int e=0; e<n; e++){
			int i,j;
			scanf("%d %d",&i,&j);
            res[i][r+j] = 1;
            AdjL[i].push_back(r+j);
            AdjL[r+j].push_back(i);
		}
        s = 0; t = r+c+1;
        printf("%d",maxFlow(AdjL));
        
        set<int> cover = vertexCover(AdjL,r,c);
        for(set<int>::iterator it = cover.begin(); it!=cover.end(); it++){
            int v = *it;
            if(v<=r)
                printf(" r%d",v);
            else
                printf(" c%d",v-r);
        }
        printf("\n");
	}
	return 0;
}
