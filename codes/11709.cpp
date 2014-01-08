#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<map>
#include<cstdio>
#include<string>

using namespace std;
int visited[1001];
stack<int> finish;

void dfs(int u,vector<int> G[], stack<int> *S=NULL){
	visited[u] = 1;
	for(int i = 0; i < G[u].size(); i++){
		int node = G[u][i];
		if(!visited[node]){
			dfs(node,G,S);
		}
	}
	if(S!=NULL)
		(*S).push(u);
}

int main(){
	int p,t;
	while(scanf("%d %d\n",&p,&t) && (p||t)){
		map<string,int> names;
		string name;
		for(int i = 0; i < p; i++){
			getline(cin,name);
			names[name] = i;
		}
		vector<int> G[p], GT[p];
		string a,b;
		for(int i = 0; i < t; i++){
			getline(cin,a);
			getline(cin,b);
			int u,v;
			u = names[a];
			v = names[b];
			G[u].push_back(v);
			GT[v].push_back(u);
		}
		memset(visited,0,sizeof(visited));

		for(int i = 0; i < p; i++){
			if(!visited[i]){
				dfs(i,G,&finish);
			}
		}

		memset(visited,0,sizeof(visited));
		int scc=0;

		while(!finish.empty()){
			int node = finish.top(); finish.pop();
			if(!visited[node]){
				dfs(node,GT);
				scc++;
			}
		}
		cout << scc <<endl;



	}
	return 0;
}
