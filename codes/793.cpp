//OK!
#include<string>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

struct UnionFind{
    vector<int> id,sz;
    UnionFind(int n): id(n),sz(n,1) {for(int i = 0; i < n; i++) id[i] = i;}
    int root(int i){
        while(i!=id[i]) i = id[i];
        return i;
    }
    void unionUF(int p, int q){
        int i = root(p);
        int j = root(q);
        if(i!=j){
            if(sz[i] < sz[j]){
                id[i] = j;
                sz[j] += sz[i];
            }
            else{
                id[j] = i;
                sz[i] += sz[j];
            }
        }
    }
    bool findUF(int p, int q){
        return root(p) == root(q);
    }
};

int main(){
    int nTests;
    scanf("%d\n",&nTests);
    scanf("\n");
    while(nTests--){
        int nComputers;
        int succes=0,unsuccess=0;
        scanf("%d\n",&nComputers);
        UnionFind UF(nComputers);
        string line;
        getline(cin,line);
        while(!line.empty()){
            int a,b;
            char c;
            char str[50];
            strcpy(str,line.c_str());
            sscanf(str,"%c %d %d",&c,&a,&b);
            a--; b--;
            if(c=='c'){
                UF.unionUF(a,b);
            }
            else if(c=='q'){
                UF.findUF(a,b) ? succes++ : unsuccess++;
            }
            getline(cin,line);
        }
        printf("%d,%d\n",succes,unsuccess);
        if(nTests) printf("\n");
    }
    return 0;
}
