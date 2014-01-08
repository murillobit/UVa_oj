#include<vector>
#include<cstring>
#include<queue>
#include<cstdio>
#define INF 2000000000
#define MAX_V 101

using namespace std;

int res[MAX_V][MAX_V], mf, f, s, t;
vector<int> p;

void augment(int v, int minEdge){
    if(v == s){
        f = minEdge;
        return;
    }
    else if(p[v] != -1){
        augment(p[v],min(minEdge,res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int maxFlow(void){
    mf = 0;
    while(true){
        f = 0;
        queue<int> q;
        vector<int> dist(MAX_V,INF);
        q.push(s);
        dist[s] = 0;
        p.assign(MAX_V,-1);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u==t) break;
            for(int v = 0; v < MAX_V; v++){
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

int main(){
    int n;
    int net=1;
    while(scanf("%d",&n) && n){
        int c;
        memset(res,0,sizeof(res));
        scanf("%d %d %d",&s,&t,&c);
        for(int i=0; i<c; i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            res[u][v] += w; res[v][u] += w;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n",net++,maxFlow());
    }

    return 0;
}
