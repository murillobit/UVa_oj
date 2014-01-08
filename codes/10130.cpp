#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		pair<int,int> objects[n];
		for(int i=0; i<n; i++){
			int p,w;
			scanf("%d %d",&p,&w);
			objects[i] = make_pair(p,w);
		}
		int g;
		scanf("%d",&g);
		int family[g];
		int max_weight = 0;
		for(int i=0; i<g; i++){
			int mw;
			scanf("%d",&mw);
			max_weight = max(max_weight,mw);
			family[i] = mw;
		}

		int dp[max_weight+1];
		memset(dp,0,sizeof(dp));

		for(int i=0; i<n; i++){
			int price = objects[i].first;
			int weight = objects[i].second;
			for(int j=max_weight; j>=weight; j--){
				dp[j] = max(dp[j],dp[j-weight]+price);
			}
		}

		int total=0;
		for(int i=0; i<g; i++){
			total+=dp[family[i]];
		}
		printf("%d\n",total);
	}
	return 0;
}
