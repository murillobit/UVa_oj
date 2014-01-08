#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int T;
	char s[1002];
	//string s;
	int L[1002][1002];
	scanf("%d",&T); getchar();
	while(T--){
		//s[0] = '\0';
		gets(s);
		//printf("s = %s\n",s);
		//scanf("%[^\n]\n",s);
		//getline(cin,s);
		//int n = s.size();
		int n = strlen(s);
		if(n==0){
			printf("0\n");
			continue;
		}
		//printf("n=%d\n",n);
		for(int i=(n-1); i>=0; i--){
			for(int j=0; j<n; j++){
				if(i > j){
					L[i][j] = 0;
				}
				else if(i==j){
					L[i][j] = 1;
				}
				else if(s[i]==s[j]){
					L[i][j] = 2 + L[i+1][j-1];
				}
				else{
					L[i][j] = max(L[i][j-1],L[i+1][j]);
				}
			}
		}
		/*for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("%d ",L[i][j]);
			}
			printf("\n");
		}*/
		printf("%d\n",L[0][n-1]);
	}
	return 0;
}
