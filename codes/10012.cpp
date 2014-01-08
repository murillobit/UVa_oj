#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		double minimo = 0x3f3f3f3f;
		int m;
		scanf("%d",&m);
		vector<double> v(m);
		for(int i=0; i<m; i++)
			scanf("%lf",&v[i]);
		if(m==1){
			printf("%.3lf\n",2*v[0]);
			continue;
		}
		vector<double> c(m);
		sort(v.begin(),v.end());
		do{
			//double sum=0;
			c[0] = v[0];
            double max_size = v[0]+c[0];
			for(int i=1; i<m; i++){
				double max_dist = -1.0;
				for(int j=0; j<i; j++){
					max_dist = max(max_dist,c[j]+(2*sqrt(v[i]*v[j])));
				}
                c[i] = max(v[i],max_dist);
                max_size = max(max_size,v[i]+c[i]);
			}
			/*for(int i=1; i<m; i++){
				double p = 2*sqrt(v[i-1]*v[i]);
				sum += max(p, max(v[i-1],v[i]));
				if(i==1){
					sum+= (p>=v[i])? v[i-1] : 0;
				}
				if(i==(m-1)){
					sum+= (p>=v[i-1])? v[i] : 0;
				}
			}
			//            sum+=v[0]+v[m-1];*/
			minimo = min(minimo,max_size);
		} while(next_permutation(v.begin(),v.end()));

		printf("%.3lf\n",minimo);
	}
	return 0;
}
