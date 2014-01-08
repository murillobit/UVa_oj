#include<cstdio>
#include<map>
#include<sstream>
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
#define INF 1000000000

using namespace std;
vector<int> dominate[210];
int custo[210], folha[210];
int dp[210][210];
int n,m;

int dfs(int node){
    int filhos=1;
    for(int i=1; i<=n; i++)
        dp[node][i] = INF;
    dp[node][0] = 0;

    for(int i=0; i<dominate[node].size(); i++){
        int filho = dominate[node][i];
        filhos += dfs(filho);
        for(int j=n; j>0; j--){
            for(int k=0; k<=j; k++){
                int m1 = j-k, m2 = k;
                dp[node][j] = min(dp[node][j],dp[node][m1]+dp[filho][m2]);
            }
        }
    }
    dp[node][filhos] = min(custo[node],dp[node][filhos]);

    return filhos;
}

int main(){
	string line;
	char str[1000];
	while(gets(str) && str[0] != '#'){
		sscanf(str,"%d %d",&n,&m);

		map<string,int> countries;
		int country=1;
		for(int i=0; i<=n; i++) dominate[i].clear();
		memset(custo,0,sizeof(custo));
		memset(folha,0,sizeof(folha));
		
		for(int i=0; i<n; i++){
			scanf("%s",str);

			string c(str);
			if(countries.count(c)==0) countries[c] = country++;
			
			int cost;
			scanf("%d",&cost);
			custo[countries[c]] = cost;

			gets(str);
			stringstream ss(str);
			string dc;

			while(ss >> dc){
				if(countries.count(dc)==0) countries[dc] = country++;
				dominate[countries[c]].push_back(countries[dc]);
				folha[countries[dc]] = 1;
			}
		}
		custo[0] = INF;
		for(int i=1; i<=n;i++){
			if(!folha[i])
			    dominate[0].push_back(i);
		}

		dfs(0);

		int result= 0x3f3f3f3f;
		for(int i=m; i<=n; i++)
			result = min(result,dp[0][i]);

		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				printf("%12d",dp[i][j]);
			}
			printf("\n");
		}

		printf("%d\n",result);

	}
	return 0;
}
