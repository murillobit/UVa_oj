#include<vector>
#include<cstdio>
#include<cmath>
#define INF 1000000000
#include<utility>
#include<algorithm>

using namespace std;
int tree[1<<21], heap[1<<21];
int k,h,n;

void buildHeap(int heapPos, int treePos, int height){
	heap[heapPos] = tree[treePos];
	if(height < h){
		int left = treePos+1;
		int right = treePos + (1<<(h-height));
		buildHeap(2*heapPos,left,height+1);
		buildHeap(2*heapPos+1,right,height+1);
	}
}

int main(){
	while(scanf("%d",&h) && h!=-1){
		scanf("%d",&k);
		n = 1 << (h+1);
		for(int i=0; i<(n-1); i++){
			scanf("%d",&tree[i]);
		}
		vector<int> dp[n];
		buildHeap(1,0,0);
		for(int node=n-1; node>0; node--){;
			if(node*2<n){
				int son1 = node*2;
				int son2 = node*2 + 1;
				dp[node] = vector<int>(min(k,(int)(dp[son1].size()+dp[son2].size())),-INF);
				dp[node][0] = heap[node];
				for(int i=0; i<min(k,(int)dp[son1].size()); i++){
					for(int j=0; j<min(k,(int)dp[son2].size()); j++){
						if((i+j+1)<k)
							dp[node][i+j+1] = max(dp[node][i+j+1],dp[son1][i]+dp[son2][j]);
					}
				}

			}
			else dp[node].push_back(heap[node]);
		}
		int maxN = -INF;
		for(int i=0; i<k; i++){
			maxN = max(maxN,dp[1][i]);
		}
		printf("%d\n",maxN);
	}
	return 0;
}
