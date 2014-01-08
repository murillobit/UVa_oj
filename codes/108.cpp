//OK!
#include<cstdio>
#include<algorithm>
const int INF = -0x3f3f3f3f;

using namespace std;

int main(){
	while(1){
		int n;
		scanf("%d\n",&n);
		int mat[n][n];
		int maxsum = INF;
		for(int i = 0; i < n; i++){
			for(int j = 0; j  < n; j++){
				int v;
				scanf("%d[ \n]",&v);
				if(!i && !j){
					mat[i][j] = v;
				}
				else if(!i){
					mat[i][j] = v+mat[i][j-1];
				}
				else if(!j){
					mat[i][j] = v+mat[i-1][j];
				}
				else{
					mat[i][j] = v + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
				}
				maxsum = max(maxsum,mat[i][j]);
			}
		}
		if(feof(stdin)) break;

		/*for(int i = 0; i < n; i++){
			for(int j = 0; j  < n; j++){
				printf("%d ",mat[i][j]);
			}
			printf("\n");
		}*/

		for(int i=0; i<n; i++){
			for(int j=0; j<n;j++){
				if(i||j){
					for(int k=n-1; k>=i; k--){
						for(int l=n-1; l>=j; l--){
							int v;
							if(i&&j){
								v = mat[k][l] - mat[i-1][l] - mat[k][j-1] + mat[i-1][j-1];
							}
							else if(i&&!j){
								v = mat[k][l] - mat[i-1][l];
							}
							else if(!i&&j){
								v = mat[k][l] - mat[k][j-1];
							}
							maxsum = max(maxsum,v);
						}
					}
				}
			}
		}
		printf("%d\n",maxsum);
	}

	return 0;
}
