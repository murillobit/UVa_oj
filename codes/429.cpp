#include<utility>
#include<iostream>
#include<queue>
#include<map>
#include<cstring>
#include<cstdio>
#include<set>

using namespace std;



int wDist(string a, string b){
	if(a.size() != b.size()) return -1;
	if(a.compare(b) == 0) return 0;
	int d=0;
	for(int i = 0; i < a.size(); i++)
		if(a[i]!=b[i]) d++;
	return d;
}

int bfs(int s, int e, vector<int> *G){
	int visited[201];
	memset(visited,0,sizeof(visited));
	queue<pair<int,int> > Q;
	
	visited[s] = 1;
	Q.push(make_pair(s,0));
	
	while(!Q.empty()){
		int parent = Q.front().first;
		int steps = Q.front().second;
		Q.pop();
		if(parent==e){
			return steps;
		}
		
		for(int i=0; i < G[parent].size(); i++){
			int son = G[parent][i];
			if(!visited[son]){
				visited[son] = 1;
				Q.push(make_pair(son,steps+1));
			}
		}
	}
}

int main(){
	int n;
	scanf("%d\n",&n);
	while(n--){
		map<string,int> dict;
		map<string,int>::iterator it;
		
		vector<int> graph[201];
		
		int nNodes=0;
		char w[12];
		
		gets(w);		
		while(strcmp(w,"*")!=0){
			dict[string(w)] = nNodes++;
			for(it = dict.begin(); it != dict.end(); it++){
				if(wDist(it->first,string(w)) == 1){
					graph[nNodes-1].push_back(it->second);
					graph[it->second].push_back(nNodes-1);
				}
			}
			gets(w);
		}

		char start[12], end[12], line[50];
		while(gets(line) && strlen(line)>0){

			sscanf(line,"%s %s", start,end);
			int result = bfs(dict[start],dict[end],graph);
			printf("%s %s %d\n", start,end,result);
			if(feof(stdin)) break;
		}
		if(n) cout << endl;
	}
	return 0;
}
