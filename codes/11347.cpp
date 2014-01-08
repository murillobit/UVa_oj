#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

typedef unsigned long long ll;

vector<ll> primeFactors(int n, vector<ll> &factors){
	ll PF_idx = 0, PF = 2;
	while(n != 1 && (PF * PF <= n)){
		while(n%PF == 0) { n /= PF; factors[PF]++; }
		PF++;
	}
	if(n!=1) factors[n]++;
	return factors;
}

int main(){
	int t;
	scanf("%d\n",&t);
	for(int i=0; i<t; i++){
		int n;
		char step[30];
		step[0] = '\0';
		scanf("%d",&n);
		scanf("%[^\n]\n",step);
		int k = strlen(step);
		vector<ll> factors(1001,0);
		while(n > 0){
			primeFactors(n,factors);
			n-=k;
		}

		ll product=1;
		bool exceed=false;
		for(int j=0; j<factors.size(); j++){
			if(factors[j]){

				if(((1000000000000000000)/(factors[j]+1)) < product){
					exceed = true;
					break;
				}
				product *= (factors[j]+1);
			}
		}

		if(!exceed) printf("Case %d: %llu\n",i+1,product);
		else printf("Case %d: Infinity\n",i+1);

	}
	return 0;
}
