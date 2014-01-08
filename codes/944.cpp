#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int dp[100001];

int happy(int n){
    if(dp[n]!=0) return dp[n];
    int q = n;
    int r;
    int sum=0;
    while(q!=0){
        r = q%10;
        q = q/10;
        sum+=r*r;
    }
    int a = happy(sum);
    dp[n] = (a>0)? a+1 : a;
    return dp[n];
}

int main(){
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    dp[10] = dp[100] = dp[1000] = dp[10000] = 2;
    dp[4] = dp[16] = dp[37] = dp[58] = dp[89] = dp[145] = dp[42] = dp[20] = -1;
    bool first = true;
    while(!feof(stdin)){
        if(!first) printf("\n");
        else first = false;
        int l,h;
        scanf("%d %d\n",&l,&h);
        for(int n=l; n<=h; n++){
            if(happy(n)>0)
                printf("%d %d\n",n,happy(n));
        }
    }
    return 0;
}
