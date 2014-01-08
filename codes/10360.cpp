#include<cstdio>
#include<utility>
#include<algorithm>
#include<cstring>

using namespace std;

int main(){
    int c;
    scanf("%d\n",&c);
    int killed[1025][1025];
    while(c--){
        int d,n;
        scanf("%d\n%d\n",&d,&n);
        memset(killed,0,sizeof(killed));
        for(int i=0; i<n; i++){
            int x,y,s;
            scanf("%d %d %d\n",&x,&y,&s);
            for(int j=max(0,(1024-y-d)); j<=min(1024,(1024-y+d)); j++){
                for(int k=max(0,x-d); k<=min(1024,x+d); k++){
                    killed[j][k] += s;
                }
            }
        }
        int biggest=0;
        int xpos=-1,ypos=-1;

        for(int j=0; j<=1024; j++){
            for(int i=1024; i>=0; i--){
                if(killed[i][j] > biggest){
                    biggest = killed[i][j];
                    xpos = j;
                    ypos = 1024-i;
                }
            }
        }

        printf("%d %d %d\n",xpos,ypos,biggest);
    }
    return 0;
}
