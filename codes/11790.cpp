//OK!
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int Lis(vector<int> H, vector<int> W){
	vector<int> sum(W.size());
	int maxsum = -0x3F3F3F3F;
	for(int i = 0; i < H.size(); i++){
		sum[i] = W[i];
		for(int j = 0; j < i; j++){
			if(H[i] > H[j]){
				sum[i] = max(sum[i], (sum[j] + W[i]));
			}
		}
		maxsum = max(maxsum,sum[i]);
	}
	return maxsum;
}

int Lds(vector<int> H, vector<int> W){
	vector<int> sum(W.size());
	int maxsum = -0x3F3F3F3F;
	for(int i = 0; i < H.size(); i++){
		sum[i] = W[i];
		for(int j = 0; j < i; j++){
			if(H[i] < H[j]){
				sum[i] = max(sum[i], sum[j] + W[i]);
			}
		}
		maxsum = max(maxsum,sum[i]);
	}
	return maxsum;
}

int main(){
	int nTests;
	scanf("%d",&nTests);
	int cases=0;
	while(nTests--){
		int nBuildings;
		cases++;
		scanf("%d",&nBuildings);
		vector<int> heights(nBuildings), widths(nBuildings);

		for(int i = 0; i < nBuildings; i++){
			scanf("%d",&heights[i]);
		}
		for(int i = 0; i < nBuildings; i++){
			scanf("%d",&widths[i]);
		}
		int lis = Lis(heights,widths);
		int lds = Lds(heights,widths);
		printf("Case %d. ",cases);
		if(lis>=lds) printf("Increasing (%d). Decreasing (%d).\n",lis,lds);
		else printf("Decreasing (%d). Increasing (%d).\n",lds,lis);

	}
	return 0;
}
