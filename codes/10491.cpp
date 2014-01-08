#include<cstdio>

using namespace std;

int main(){
    while(!feof(stdin)){
        double ncars,ncows,nshow,n;
        scanf("%lf %lf %lf\n",&ncows,&ncars,&nshow);
        n = ncows+ncars;
        printf("%.5lf\n",(ncars*(n-1))/(n*(n-1-nshow)));
    }
    return 0;
}
