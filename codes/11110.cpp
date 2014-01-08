#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int npontos;
int grid[102][102];

int dfs(int x, int y, int cor, int n){
	if(x<0 || y<0 || x>=n || y >=n)
		return 0;
	if(grid[x][y] == -1 || grid[x][y] != cor)
		return 0;
	grid[x][y] = -1;
	npontos++;
	return 1 + dfs(x-1,y,cor,n) + dfs(x+1,y,cor,n) + dfs(x,y-1,cor,n) + dfs(x,y+1,cor,n);
}
void print(int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ",grid[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int n;
	while(scanf("%d\n",&n) && n){
		memset(grid,0,sizeof(grid));
		for(int i = 1; i <= n-1; i++){
			int x,y;
			char *p,line[5000];
			gets(line);
			p = strtok(line," ");
			while(p!=NULL){
				x = atoi(p);
				p = strtok(NULL," ");
				y = atoi(p);
				grid[x-1][y-1] = i;
				p = strtok(NULL," ");
			}
		}
		bool wrong = false;
		npontos=0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(npontos==n*n) break;
				if(grid[i][j] != -1){
					if(dfs(i,j,grid[i][j],n) != n){
						wrong = true;
						break;
					}
				}
			}
			if(wrong || npontos==n*n) break;
		}
		cout << (wrong? "wrong\n" : "good\n");
	}
	return 0;
}
