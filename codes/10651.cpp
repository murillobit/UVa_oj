#include<string>
#include<iostream>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b))? a:b
#define pedra(x,k) (((x) >> (k)) & 1)

using namespace std;

int dp[1<<12];

int score(int x){
	if (dp[x] >= 0) return dp[x]; //se ja calculou o valor daquela configuraçao

	dp[x]=0;
	for (int i = 0; i < 12; i++) //conta quantidade de bits 1 (pedras)
		dp[x] += pedra(x,i);//(a >> i) & 1;

	for (int i = 1; i < 11; i++)
		if (pedra(x,i) == 1 && (pedra(x,i-1) ^ pedra(x,i+1)) == 1) //verifica se há como realizar um movimento entre i-1, i e i+1
			dp[x] = min(dp[x], score(x ^ (7 << (i-1)))); //verifica a quantidade da configuraçao apos o movimento

	return dp[x];
}

int main(){
	int nTests;

	for (int i = 0; i < 4096; i++) dp[i] = -1;
	for (int i = 0; i < 4096; i++) score(i);
	
	scanf("%d\n", &nTests);
	
	while(nTests--){
		string s;
		getline(cin,s);
		int x=0;
		for (int i = 0; i < 12; i++)
			if (s[i] == 'o')
				x = (x << 1) | 1; //se tem pedra, o bit=1
			else if (s[i] == '-')
				x = x << 1; //se nao tem pedra, o bit =0
		printf("%d\n", dp[x]);
	}
	return 0;
}
