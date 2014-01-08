#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>

#define INF 0x3f3f3f3f

using namespace std;

int main(){
    while(!feof(stdin)){
        string name;
        getline(cin,name);
        cout << name << endl;
        int n,m;
        scanf("%d %d",&n,&m);
        int cost[m*n+1];
        memset(cost,INF,sizeof(cost));
        int smallest_cost = INF;

        for(int k=0; k<(n-1); k++){
            for(int i=1; i<=m; i++){
                for(int j=1; j<=m; j++){
                    //printf("km+i = %d, k = %d, i = %d, j = %d\n", k*m+i,k,i,j);
                    if(k==0) cost[k*m+i] = 0;
                    
                    int pre_cost;
                    scanf("%d",&pre_cost);
                    //printf("Custo para chegar até %c: %d\n",'A'+((k+1)*m+j-1), cost[(k+1)*m+j]);
                    //printf("Custo para chegar até %c: %d\n",'A'+(k*m+i-1), cost[k*m+i]);
                    //printf("Custo para ir de %c até %c: %d + %d + 2 = %d\n",'A'+(k*m+i-1), 'A'+((k+1)*m+j-1), cost[k*m+i], pre_cost, cost[k*m+i] + pre_cost + 2);
                    pre_cost += cost[k*m+i] + 2;
                    int pos_cost = cost[(k+1)*m+j];

                    cost[(k+1)*m+j] = (pre_cost < pos_cost ? pre_cost : pos_cost);
                    pos_cost = cost[(k+1)*m+j];
                    
                    if(k==n-2)
                        smallest_cost = (smallest_cost < pos_cost ? smallest_cost : pos_cost);
                    
                    if(j==m) scanf("\n");
                    //cout << endl;
                }
            }
        }

        cout << smallest_cost << endl;
    }
    return 0;
}
