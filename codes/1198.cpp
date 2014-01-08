#include<cstdlib>
#include<vector>
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define INF 100
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)


using namespace std;

typedef unsigned long long ull;

int main(){
	int n;
	string s;
	string digits = "0123456789";
	getline(cin,s);
	n = atoi(s.c_str());
	int g[n][n];
	ull path[n][n];

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			g[i][j] = (i==j)? 0 : INF;	
			path[i][j] = (i==j)? 1ull<<i : 0;
		}
	}


	for(int i=0; i<n; i++){
		getline(cin,s);
		size_t found = s.find_first_of(digits);
		while(found != string::npos){
			size_t last = s.find_first_not_of(digits,found+1);
			string ss(s,found,last-found);
			int j = atoi(ss.c_str());
			j--;
			g[i][j] = 1;
			path[i][j] = path[i][i] | path[j][j];
			found = s.find_first_of(digits,last);
		}
	}
	REP (k, 0, n - 1){ // recall that #define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
		REP (i, 0, n - 1){
			REP (j, 0, n - 1){
				if(g[i][j] == (g[i][k]+g[k][j])){//há dois menores caminhos
					path[i][j] |= path[i][k] | path[k][j];
				}
				else if(g[i][j] > (g[i][k]+g[k][j])){//substitui o antigo menor caminho
					g[i][j] = g[i][k]+g[k][j];
					path[i][j] = path[i][k] | path[k][j];
				}
			}
		}
	}
	int t;
	getline(cin,s);
	t = atoi(s.c_str());
	for(int c=0; c<t; c++){
		vector<int> D;
		ull subset = 0;
		getline(cin,s);
		size_t found = s.find_first_of(digits);
		while(found != string::npos){
			size_t last = s.find_first_not_of(digits,found+1);
			string ss(s,found,last-found);
			int v = atoi(ss.c_str());
			D.push_back(v-1);
			found = s.find_first_of(digits,last);
		}
		for(int i=0; i<D.size(); i++){
			for(int j=0; j<D.size(); j++){
				subset |= path[D[i]][D[j]];
			}
		}
		if(subset == ((1ull << n)-1))
			printf("yes\n");
		else 
			printf("no\n");
	}
	return 0;
}
