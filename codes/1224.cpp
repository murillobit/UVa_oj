#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    int tc[31],tcs[31];
    tc[0] = tc[1] = 1;
    tcs[0] = tcs[1] = tcs[3] = 1;
    tcs[2] = 3;
    for(int i=2;i<31;i++){
        tc[i] = tc[i-1] + 2*tc[i-2];
	if(i>3)
		tcs[i] = tcs[i-2] + 2*tcs[i-4];
    }
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        printf("%d\n",(tc[n]-tcs[n])/2 + tcs[n]);
    }
    return 0;
}
