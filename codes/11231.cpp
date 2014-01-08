#include<cstdio>

using namespace std;

int main(){
    int n,m,c;
    while(scanf("%d %d %d",&n,&m,&c) && (n||m||c)){
        int a = (n-7)*(m-7);
        printf("%d\n",(a%2 == 0)? (a/2):(a/2 + c));
    }
    return 0;
}
