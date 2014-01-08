#include<set>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<iostream>
#include<string>
#include<utility>
#include<map>

using namespace std;
int G[10001][10001],n,vis[10005];
set<int> visited;

pair<int,int> dfs(int u, vector<pair<int,int> > *g){
    pair<int,int> vMax(u,0);
//    vis[u] = 1;
    visited.insert(u);
//    for(int k=0; k<n; k++){
    for(int i=0; i<g[u].size(); i++){
        int k = g[u][i].first;
        int w = g[u][i].second;
//        if(G[u][k]!=0){
//            if(vis[k]==0){
            if(visited.count(k)==0){
                pair<int,int> v = dfs(k,g);
//                if((v.second+G[u][k]) > vMax.second){
//                    vMax = make_pair(v.first,(v.second+G[u][k]));
                if((v.second+w) > vMax.second){
                    vMax = make_pair(v.first,(v.second+w));
                }
            }
//        }
    }
    return vMax;
}

int main(){
    while(!feof(stdin)){
//        string line;
//        getline(cin,line);
        char line[50];
/*        gets(line);
        if(!strlen(line)){
//        if(!line.size()){
            printf("0\n");
            continue;
        }*/
        n=-1;
//        memset(G,0,sizeof(G));
        vector<pair<int,int> > g[10001];
//        while(line.size()){
        while(gets(line) && strlen(line)>0){
//            strcpy(cline,line.c_str());
            int src,dst,w;
//            sscanf(line.c_str(),"%d %d %d",&src,&dst,&w);
            sscanf(line,"%d %d %d",&src,&dst,&w);
            n = max(n, max(src,dst) );
            g[src].push_back(make_pair(dst,w));
            g[dst].push_back(make_pair(src,w));
//            G[src][dst] = w;
  //          G[dst][src] = w;
  //          printf("%d %d %d\n",src,dst,w);
//            getline(cin,line);
//            gets(line);
        }
//        printf("\n%d ok\n",n);
        
        n++;
        if(n==0){
            printf("0\n");
            continue;
        }
        if(visited.size()>0)visited.clear();
//        memset(vis,0,sizeof(vis));
        pair<int,int> result = dfs(n-1,g);
//        memset(vis,0,sizeof(vis));
        visited.clear();
        result = dfs(result.first,g);
        printf("%d\n",result.second);
        /*for(int i=0; i<n; i++){
            for(int j=0; j<G[i].size(); j++){
                printf("%d-%d:%d\n",i,G[i][j].first,G[i][j].second);
            }
        }*/
    }
    return 0;
}
