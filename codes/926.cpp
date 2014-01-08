#include<cstdio>
#include<cstring>

using namespace std;


int main(){
    int c;
    scanf("%d\n",&c);
    while(c--){
        int n;
        scanf("%d\n",&n);
        int G[n*n][n*n];
        memset(G,0,sizeof(G));
        
        int a,b,s,e;
        scanf("%d %d\n",&a,&b);
        a--; b--;
        s = n*a+b;
        scanf("%d %d\n",&a,&b);
        a--; b--;
        e = n*a+b;
//        printf("%d %d\n",s,e);

        for(int x=0; x<n; x++){
            for(int y=0; y<n; y++){
                if(x<(n-1)){
                    G[n*x+y][n*(x+1)+y] = 1;
                }
                if(y<(n-1)){
                    G[n*x+y][n*x+(y+1)] = 1;
                }
            }
        }

        int w;
        scanf("%d\n",&w);
        while(w--){
            int src,dst;
            char dir;
            scanf("%d %d %c\n",&a,&b,&dir);
            a--; b--;
            //printf("%d %d %c\n",a,b,dir);
            switch(dir){
                case 'N':
                    src = n*a+b;
                    dst = n*a+(b+1);
                    break;
                case 'E':
                    src = n*a+b;
                    dst = n*(a+1)+b;
                    break;
                case 'S':
                    src = n*a+(b-1);
                    dst = n*a+b;
                    break;
                case 'W':
                    src = n*(a-1)+b;
                    dst = n*a+b;
                    break;
            }
//            printf("%d -> %d\n",src,dst);
            G[src][dst] = 0;
        }
        unsigned long long N[n*n];
        N[s] = 1;

        for(int nivel=0; nivel<=(2*(n-1)); nivel++){
//            printf("\nnivel %d\n",nivel);
            int upper,lower;
            if(nivel<=(n-1)){
                lower = 0;
                upper = nivel;
            }
            else{
                lower = nivel - (n-1);
                upper = n-1;
            }
            while(lower <= upper){
                int x = lower, y = (nivel-lower);
                int v = n*x+y;
                if(v!=s){
                    unsigned long long soma = 0;
//                    printf("%d %d: %d\n",x,y,v);
                    for(int i=0; i<(n*n); i++){
                        if(G[i][v] == 1){
                            soma += N[i];
                        }
                    }
//                    printf("%d\n",soma);
                    N[v] = soma;
                }
                lower++;
            }
        }

        printf("%lld\n", N[e]);

    }
    /*
    int G[9][9];
    memset(G,0,sizeof(G));
    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            if(x<2){
                G[3*x + y][3*(x+1) + y] = 1;
            }
            if(y<2){
                G[3*x + y][3*x + (y+1)] = 1;
            }
        }
    }
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }*/

    return 0;
}
