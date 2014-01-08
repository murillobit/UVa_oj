#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define INF 2000000000

using namespace std;

int AdjM[202][202], res[202][202], mf, f, s, t, A[101],B[101];
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

int maxFlow(void){
    mf = 0;
    while(true){
        f=0;
        queue<int> q;
        vector<int> dist(202,INF);
        q.push(s);
        dist[s] = 0;
        p.assign(202,-1);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u==t) break;
            for(int v=0; v<202; v++){
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
    int T;
    scanf("%d",&T);
    for(int c=1; c<=T; c++){
        memset(res,0,sizeof(res));
        int n,m,w;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d",&w);
            A[i] = w;
            res[0][i+1] = 1;
            AdjM[0][i+1] = 1;
        }
        scanf("%d",&m);
        for(int i=0; i<m; i++){
            scanf("%d",&w);
            B[i] = w;
            res[n+i+1][n+m+1] = 1;
            AdjM[n+i+1][m+n+1] = 1;
            for(int j=0; j<n; j++){
                if(A[j] != 0){
                    if(B[i] % A[j] == 0){
                        res[j+1][n+i+1] = 1;
                        AdjM[j+1][n+i+1] = 1;
                    }
                }
                else if(B[i] == 0){
                    res[j+1][n+i+1] = 1;
                    AdjM[j+1][n+i+1] = 1;
                }
            }
        }
        s = 0; t = n+m+1;
        printf("Case %d: %d\n",c,maxFlow());
    }
    return 0;
}
