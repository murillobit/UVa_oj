#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool myfunction (int i,int j) { return (i>j); }

int main(){
	int n;
	while(scanf("%d",&n) && n){
		vector<int> d(n);
		int sum=0;
		for(int i = 0; i < n; i++){
			scanf("%d",&d[i]);
			sum+=d[i];
		}
		if(sum%2!=0){
			cout << "Not possible\n";
			continue;
		}
		sort(d.begin(),d.end(),myfunction);
		
		bool possible=true;
		int k;
		for(k = 1; k <= n; k++){
			int Di=0;
			for(int i = 1; i <=k; i++){
				Di += d[i-1];
			}
			int minDiK=0;
			for(int i = k+1; i <= n; i++){
				minDiK += min(d[i-1],k);
			}
			if(Di > k*(k-1) + minDiK){
				possible = false;
				break;
			}
		}
		if(possible) cout << "Possible\n";
		else cout << "Not possible\n";
	}
	return 0;
}
