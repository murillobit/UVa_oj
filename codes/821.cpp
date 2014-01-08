#include<cstdio>
#include<cstring>
#include<iostream>
#define inf 0x3f3f3f3f

using namespace std;

int main(){
	int a,b;
	int g[102][102];
	int map[102];
	int nTests=0;
	while(scanf("%d%d",&a,&b) && (a||b)){
		memset(g,inf,sizeof(g));
		memset(map,0,sizeof(map));
		int n=0;
		while(a||b){
//			cout << a << " " << b << endl;
			if(!map[a]) map[a] = ++n;
			if(!map[b]) map[b] = ++n;
			g[map[a]][map[b]] = 1;
			scanf("%d%d",&a,&b);
		}
	/*	for(int i=1; i <=n; i++){
			for(int j=1; j<=n; j++){
				printf("%d ",g[i][j]);
			}
			cout << endl;
		}
		cout << endl;*/
		double sum=0;

		for(int k=1; k<=n; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					g[i][j] = min(g[i][j], (g[i][k]+g[k][j]));
					if(k==n && i!=j) sum+= g[i][j];
				}
			}
		}
		for(int i=1; i <=n; i++){
			for(int j=1; j<=n; j++){
				printf("%d ",g[i][j]);
			}
			cout << endl;
		}
		cout << endl;
		sum /=(n*(n-1));
		printf("Case %d: average length between pages = %.3lf clicks\n",++nTests,sum);
	}
	return 0;
}
