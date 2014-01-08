#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int gcd(int a, int b){
    if(b != 0) return gcd(b,a%b);
    return abs(a);
}

int lcm(int a, int b){
    return abs(a*b)/gcd(a,b);
}


int main(){
    int n,t;
    while(scanf("%d %d",&n,&t) && (n||t)){
        int coins[51];
        for(int i=0; i<n; i++){
            scanf("%d",&coins[i]);
        }
        for(int i=0; i<t; i++){
            int height;
            int hmin=0,hmax=0x3f3f3f3f;
            bool exact=false;
            scanf("%d",&height);
            for(int j=0; j<(n-3); j++){
                for(int k=j+1; k<(n-2); k++){
                    for(int l=k+1; l<(n-1); l++){
                        for(int m=l+1; m<n; m++){
                            int mmc = lcm(lcm(coins[j],coins[k]),lcm(coins[l],coins[m]));
                            int h = (height/mmc)*mmc;
                            if(h==height){
                                hmin = hmax = h;
                                exact = true;
                                break;
                            }
                            else{
                                hmin = max(hmin,h);
                                hmax = min(hmax,(h+mmc));
                            }
                        }
                        if(exact) break;
                    }
                    if(exact) break;
                }
                if(exact) break;
            }
            printf("%d %d\n",hmin,hmax);
        }
    }
/*    n=6;
    char s[] = "ABCDEF";
    for(int i = 0; i < (n-3); i++)
        for(int j = i+1; j < (n-2); j++)
            for(int k = j+1; k < (n-1); k++)
                for(int l = k+1; l < n; l++)
                    printf("%c%c%c%c\n",s[i],s[j],s[k],s[l]);*/
    return 0;
}
