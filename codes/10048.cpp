#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f3f

using namespace std;

int main(){
	int c,s,q;
	int nTests=1;
	while(scanf("%d %d %d",&c,&s,&q) && (c||s||q)){
		if(nTests>1) cout << endl;

		int G[102][102];
		memset(G,inf,sizeof(G));
		for(int i=0; i<s; i++){
			int c1,c2,d;
			scanf("%d %d %d",&c1,&c2,&d);
//			printf("%d,%d,%d\n",c1,c2,d);
			G[c1][c2] = G[c2][c1] = d;
		}
//		cout << endl;

		for(int k=1; k<=c; k++){
			for(int i=1; i<=c; i++){
				for(int j=1; j<=c; j++){
					G[i][j] = min(G[i][j], max(G[i][k],G[k][j]));
				}
			}
		}

		printf("Case #%d\n",nTests++);
		for(int i=0; i<q; i++){
			int c1,c2;
			scanf("%d %d",&c1,&c2);
			if(G[c1][c2] != inf) cout << G[c1][c2];
			else cout << "no path";
			cout << endl;
		}
	}
	return 0;
}
