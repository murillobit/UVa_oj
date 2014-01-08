//OK!
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
	while(!feof(stdin)){
		long long int n;
		scanf("%lld\n",&n);
		long long int dp[n+1];
		memset(dp,0,sizeof(dp));
		long long int coins[] = {1,5,10,25,50};
		dp[0]=1;
		for(long long int i = 0; i < 5; i++){
			long long int coin = coins[i];
			for(long long int j = coin; j<=n; j++){
				dp[j] += dp[j-coin];
			}
		}
		long long int m = dp[n];
		printf((m>1 ? "There are %lld ways to produce %lld cents change.\n" : "There is only %lld way to produce %lld cents change.\n"),m,n);
	}
	return 0;
}
