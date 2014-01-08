#include<vector>
#include<utility>
#include<iostream>
#include<cstdio>
#include<queue>
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int,int> point;

int r,c;
int changes[2][4] = {{-1,0,1,0},{0,-1,0,1}};
int visited[1005][1005];
char grid[1005][1005];

int bfs(point start, queue< point > &fires){
	queue< point > Q;
	Q.push(start);
	visited[start.first][start.second] = 0;
	int firesteps = 0;
	
	while(!Q.empty()){
		point p = Q.front();
		int pi = p.first;
		int pj = p.second;
		Q.pop();

		if(visited[pi][pj] == firesteps){
			int n = fires.size();
			for(int i = 0; i < n; i++){
				point f = fires.front();
				int fi = f.first;
				int fj = f.second;
				fires.pop();

				for(int k = 0; k < 4; k++){
					int ffi = fi + changes[0][k];
					int ffj = fj + changes[1][k];
					if(ffi>=0 && ffj >=0 && ffi < r && ffj < c){
						if(grid[ffi][ffj] != '#' && grid[ffi][ffj] != 'F'){
							grid[ffi][ffj] = 'F';
							fires.push(make_pair(ffi,ffj));
						}
					}
				}
			}
			firesteps++;
		}
		
		if(pi==0 || pi == (r-1) || pj == 0 || pj == (c-1)){
			return visited[pi][pj]+1;
		}
		
		for(int i = 0; i < 4; i++){
			int si = pi+changes[0][i];
			int sj = pj+changes[1][i];
			if(si>=0 && sj >=0 && si < r && sj < c){
				if(grid[si][sj] == '.' && (visited[pi][pj]+1) < visited[si][sj]){
					point s = make_pair(si,sj);
					visited[si][sj] = visited[pi][pj]+1;
					Q.push(s);
				}
			}
		}
		
	}
	return -1;
}


int main(){
	int nTests;
	scanf("%d\n",&nTests);
	while(nTests--){
		scanf("%d %d\n",&r,&c);
		queue< point > fires;
		point start;
		
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				scanf("%c",&grid[i][j]);
				visited[i][j] = INF;
				if(grid[i][j] == 'F') fires.push(make_pair(i,j));
				if(grid[i][j] == 'J'){
					start = make_pair(i,j);
					grid[i][j] = '.';
				}
			}
			scanf("\n");
		}
		
		int result = bfs(start,fires);
		if(result == -1) cout << "IMPOSSIBLE\n";
		else cout << result << endl;
	}
	return 0;
}
