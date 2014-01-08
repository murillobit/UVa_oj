#include<cmath>
#include<cstdio>

using namespace std;

long long x,y,d;

void extendedEuclid(long long a,long long b){
	if(b==0) {x = 1; y = 0; d = a; return;}
	extendedEuclid(b, a%b);
	long long x1 = y;
	long long y1 = x - (a / b) * y;
	x = x1;
	y = y1;
}

int main(){
    long long n;
	while(scanf("%lld",&n) && (n)){
		long long c1,c2,n1,n2;
		scanf("%lld %lld",&c1,&n1);
		scanf("%lld %lld",&c2,&n2);
		extendedEuclid(n1,n2);
//	    printf("%lld %lld %lld\n",x,y,d);
        if(n%d != 0){
            printf("failed\n");
            continue;
        }
	    //printf("%lld %lld %lld\n",x,y,d);
        long long x0 = x*n/d;
        long long y0 = y*n/d;
        //printf("\n%lldx%lld + %lldx%lld = %lld\n",n1,x0,n2,y0,n);
        long long lower = (long long)ceil((double)(-1*(x0)*d)/(double)(n2));
        long long upper = (long long)floor((double)(y0*d)/(double)(n1));
        if(lower>upper){
            printf("failed\n");
            continue;
        }
//        printf("%lld <= n <= %lld\n",lower,upper);
        long long xlower = x0 + (n2/d)*lower;
        long long ylower = y0 - (n1/d)*lower;
        long long xupper = x0 + (n2/d)*upper;
        long long yupper = y0 - (n1/d)*upper;
        if((xlower*c1 + ylower*c2) <= (xupper*c1 + yupper*c2)){
            printf("%lld %lld\n",xlower,ylower);
        }
        else{
            printf("%lld %lld\n",xupper,yupper);
        }
    }
	return 0;
}
