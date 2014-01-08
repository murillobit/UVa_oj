#include<cstdio>

using namespace std;

int main(){
	int nTests;
	scanf("%d",&nTests);
	for(int t=0; t < nTests; t++){
		int D,I;
		scanf("%d %d",&D,&I);
		I--;
		int x=1;
		for(int i=0; i < (D-1); i++){
			x = (x<<1)|((I>>i)&1);
		}
		printf("%d\n",x);
	}
	scanf("-1\n");
	return 0;
}
