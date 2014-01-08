#include<set>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int time_s, visit[101];

int dfs(int u, vector<vector<int> > G,set<int>& ans){
    int menor = visit[u] = time_s++;
    int filhos = 0;
    for(int i =0; i < G[u].size(); i++){
        if(visit[G[u][i]] ==0){
            filhos++;
            int m = dfs(G[u][i],G,ans);
            menor = min(menor,m);
            if(visit[u]<=m && (u!=0 || filhos>=2)){
                ans.insert(u);
            }
        }
        else{
                menor = min(menor,visit[G[u][i]]);
        }
    }
    return menor;
}

int main(){
    int n;
    while(scanf("%d\n",&n) && n){
        vector<vector<int> > graph(n);
        int v,u;
        while(scanf("%d",&u)&&u){
            char line[3000];
            scanf("%[^\n]\n",line);
            char *p = line;
            while(p!=NULL){
                sscanf(p,"%d",&v);
                graph[u-1].push_back(v-1);
                graph[v-1].push_back(u-1);
                p = strpbrk(p+1," \n");
            }
        }      
/*
        for(int i =0; i<graph.size(); i++){
            cout << i << ": ";
            for(int j = 0; j < graph[i].size(); j++){
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
*/
        time_s=1;
        memset(visit,0,sizeof(visit));
        set<int> ans;
        dfs(0,graph,ans);
        cout << ans.size() << endl;
   //     set<int>::iterator it;
    //    for(it = ans.begin(); it != ans.end(); it++)
      //      cout << "> " << *it << endl;
    }
    return 0;
}
