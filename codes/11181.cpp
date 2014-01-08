#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n,r,test=0;
    while(scanf("%d %d",&n,&r) && (n||r)){
        printf("Case %d:\n",++test);
        double p[n],q[n];
        for(int i=0; i<n; i++){
            scanf("%lf",&p[i]);
//            printf("%lf\n",p[i]);
            q[i]=0;
        }
    
        int lower=0;
        for(int i=0; i<r;i++){
            lower = (lower << 1) | 1;
        }
        int upper = lower;
        for(int i=0; i<(n-r); i++){
            upper = (upper << 1);
        }
//        printf("%d-%d\n",lower,upper);

        double pt=0;
        for(int i=lower; i<=upper; i++){
            int count=0;
            int subset=i;
            int bit=0;
            double prob=1;
            while(bit<n){
                if(subset & 1){
                   count++;
                   prob *= p[bit];
                }
                else prob *= (1-p[bit]);
                subset = (subset >> 1);
                bit++;
            }
            if(count == r){
//               printf("%d %lf\n",i,prob);
               for(int j=0;j<n;j++){
                   int mask = pow(2,j);
//                   printf("%d & %d = %d\n",i,mask,i&mask);
                   if(i & mask)
                       q[j] += prob;
               }
               pt+=prob;
            }
        }
//        printf("PT = %lf\n",pt);
        for(int i=0;i<n;i++) printf("%.6lf\n",q[i]/pt);
    }
    return 0;
}
