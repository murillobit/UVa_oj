#include<cmath>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
    while(!feof(stdin)){
        double x,y,c;
        scanf("%lf %lf %lf\n",&x,&y,&c);
        double lo=0, hi=max(x,y);
        double L;
        while(fabs(hi-lo) > 1e-9){
//            printf("lo %lf hi %lf\n",lo,hi);
            L = (lo+hi)/2.0;
            double u,h,g;
            if(x<=L || y<=L){
                u = 0.0;
            }
            else{
                h = sqrt(x*x - L*L);
                g = sqrt(y*y - L*L);
                u = (h*g)/(h+g);
            }
            //double u = (h==0 || g==0)? 0 : (g*h)/(g+h);
//            printf("h %lf g %lf u %lf lo %lf hi %lf\n",h,g,u,lo,hi);
            if(u<c) hi = L;
            else lo = L;
        }
        printf("%.3lf\n",L);
    }
    return 0;
}
