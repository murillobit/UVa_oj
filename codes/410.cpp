//OK!
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<utility>
#include<vector>

using namespace std;

int main(){
	int nCase=0;
	do{
		nCase++;
		int C,S;
		scanf("%d %d\n",&C,&S);

		vector<int> species(2*C);
		double avg=0,imbalance=0;
		for(int i=0; i<S; i++){
			scanf("%d",&species[i]);
			avg+=species[i];
		}
		scanf("\n");
		for(int i=S; i<2*C; i++){
			species[i]=0;
		}
		avg/=C;
		sort(species.begin(),species.end());
		vector<pair<int,int> > chambers(C);
		for(int i=0; i<C; i++){
			chambers[i] = pair<int,int>(species[i],species[2*C-1-i]);
			imbalance+=abs(chambers[i].first + chambers[i].second - avg);
		}
		printf("Set #%d\n",nCase);
		for(int i=0; i<C; i++){
			printf(" %d:",i);
			if(chambers[i].first) printf(" %d",chambers[i].first);
			if(chambers[i].second) printf(" %d",chambers[i].second);
			printf("\n");
		}
		printf("IMBALANCE = %.5lf\n\n",imbalance);

	} while(!feof(stdin));
	return 0;
}
