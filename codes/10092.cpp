#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define INF 2000000000
#define MAX_V 1022

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

int main(){
	int nk,np;
	while(scanf("%d %d",&nk,&np) && (nk||np)){
		memset(res,0,sizeof(res));
		vector<int> AdjL[nk+np+2];
		int tQ = 0;
		for(int i=0; i<nk; i++){
			int q;
			scanf("%d",&q);
			res[0][i+1] = q;
			AdjL[0].push_back(i+1);
			AdjL[i+1].push_back(0);//importante!
			tQ += q;
		}
		for(int i=0; i<np; i++){
			int k;
			scanf("%d",&k);
			for(int j=0; j<k; j++){
				int c;
				scanf("%d",&c);
				res[c][nk+i+1] = 1;
				AdjL[c].push_back(nk+i+1);
				AdjL[nk+i+1].push_back(c);//importante
			}
			res[nk+i+1][nk+np+1] = 1;
			AdjL[nk+i+1].push_back(nk+np+1);
			AdjL[nk+np+1].push_back(nk+i+1);//importante
		}
		s = 0; t = np+nk+1;
		int success = (maxFlow(AdjL) == tQ? 1 : 0);
		printf("%d\n",success);
		if(success){
			for(int j=1; j<=nk; j++){
				int p=1;
				for(int i=1; i<nk+np+1; i++){
					if(res[i][j] == 1)
						printf("%d%s",i-nk,(p++ == res[j][0])?"\n":" ");
				}
			}
		}
/*		for(int i=0; i<nk+np+2; i++){
			for(int j=0; j<nk+np+2; j++){
				printf("%d ",res[i][j]);
			}
			printf("\n");
		}
		printf("---\n");
		for(int i=0; i<nk+np+2; i++){
			for(int j=0; j<nk+np+2; j++){
				printf("%d ",AdjM[i][j]);
			}
			printf("\n");
		}*/

	}
	return 0;
}
