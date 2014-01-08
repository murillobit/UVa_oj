#include<queue>
#include<utility>
#include<iostream>
#include<cstdio>
#include<vector>
#define INF 2000000000

using namespace std;
typedef unsigned long UL;
typedef pair<UL,UL> ii;

int changes[2][4] = {{1,0,-1,0},{0,1,0,-1}};
int A[1000000];
int n,m;

int dijkstra(int s){
    vector<UL> dist(n*m,INF);
    //vector<int> visited(n*m,0);
    priority_queue< ii, vector< ii >, greater< ii > > pq;
    pq.push(make_pair(A[s],s));
    dist[s] = A[s];
    while(!pq.empty()){
        UL d = pq.top().first;
        UL u = pq.top().second;
        UL x = u/m;
        UL y = u%m;
        pq.pop();
        if(d==dist[u]){
            for(int j=0; j<4; j++){
                UL xx = x+changes[0][j];
                UL yy = y+changes[1][j];
                if(xx>=0 && yy>=0 && xx<n && yy<m){
                    UL v = m*xx + yy;
                    if(dist[u] + A[v] < dist[v]){
                        dist[v] = dist[u] + A[v];
                        pq.push(make_pair(dist[v],v));
                    }
                }
            }
        }
    }
    return dist[n*m-1];
}

int main(){
    int nMazes;
    scanf("%d",&nMazes);
    while(nMazes--){
        //int n,m;
        scanf("%d\n%d",&n,&m);
        //int A[n*m+1];
        for(UL i=0; i < (n*m); i++){
            scanf("%d",&A[i]);
        }
        
        /*for(int i=0; i < (n*m); i++){
            printf("%d ",A[i]);
            if((i+1)%m == 0) cout << endl;
        }*/
        cout << dijkstra(0) << endl;
    }
    return 0;
}
