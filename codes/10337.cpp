//OK!
#include<iostream>
#include<cstdio>
const int INF = 0x3f3f3f3f;

using namespace std;

int main(){
	int nTests;
	scanf("%d",&nTests);
	while(nTests--){
		int n;
		scanf("%d",&n);
		n /= 100;
		int matriz[10][n],custo[10][n];
		for(int i = 9; i >=0; i--){
			for(int j = 0; j < n; j++){
				int a;
				scanf("%d",&a);
			    	if(n<=18 && i > (n/2)){
			    		a = -INF;
			    	}
			    	if((n>18)||( (n<=18)&&(i<=(n/2)) )){
			        	if(j<i || (j+i)>n)
			        	a = -INF;
			    	}
			    	if(i==0 && 0 < j && j < n){
			        	a = -INF;
			    	}
			    	matriz[i][j] = a;
				custo[i][j] = 0;
			}
	    	}
		for(int j = 1; j < n; j++){
			for(int i = 1; i <= min(j,min(9,n-j)); i++){
				int subir,manter,descer;
				subir = custo[i-1][j-1] + 60 - (matriz[i-1][j-1]);
				manter = custo[i][j-1] + 30 - (matriz[i][j-1]);
				descer = custo[min((i+1),9)][j-1] + 20 - (matriz[min((i+1),9)][j-1]);
				printf("[%d,%d]: %d,%d,%d\n",i,j,subir,manter,descer);
				custo[i][j] = min(subir,min(manter,descer));
	    		}
		}
		for(int i = 9; i>=0; i--){
			for(int j=0;j<n;j++){
				printf("%11d ",matriz[i][j]);
			}
	    		printf("\n");
		}
		printf("\n");
		for(int i = 9; i>=0; i--){
			for(int j=0;j<n;j++){
				printf("%11d ",custo[i][j]);
			}
			printf("\n");
		}
		
		cout << (custo[1][n-1] + 20 - matriz[1][n-1]) << endl << endl;
	}
	return 0;
}
