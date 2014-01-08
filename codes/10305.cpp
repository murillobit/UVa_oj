#include<vector>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

int visited[102];

void dfs(int u, vector<int>* T, stack<int> &O){
    if(visited[u]) return;
    visited[u] = 1;
    for(int i =0; i < T[u].size(); i++){
        dfs(T[u][i],T,O);
    }
    O.push(u);
}

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m) && (n||m)){
    	int dependent[102];
        memset(dependent,0,sizeof(dependent));
        memset(visited,0,sizeof(visited));
        vector<int> tasks[102];
        
        if(!m){
        	for(int i = 1; i <=n; i++)
        		cout << i << (i==n? "\n" : " ");
        	continue;
        }
        for(int i = 0; i < m; i++){
            int a,b;
            scanf("%d %d",&a,&b);
            dependent[b] = 1;
            tasks[a].push_back(b);
        }
        stack<int> order;
        for(int i=1; i <=n; i++){
            if(!dependent[i] && !visited[i]){
                dfs(i,tasks,order);
            }
        }
        while(!order.empty()){
            cout << order.top();
            order.pop();
            cout << (order.empty()? "" : " ");
        }
        cout << endl;
    }
    return 0;
}
