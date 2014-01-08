//OK!
#include<cstdio>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct unionfind{
    vector<int> id,sz;
    unionfind(int n): id(n), sz(n,1) {for (int i = 0; i < id.size(); i++) id[i] = i;}
    int root(int i){
        while(i != id[i]) i = id[i];
        return i;
    }
    void unionUF(int p, int q){
        int i = root(p);
        int j = root(q);
        if(i!=j){
            if(sz[i] < sz[j]) {
                id[i] = j;
                sz[j] += sz[i];
            }
            else {
                id[j] = i;
                sz[i] += sz[j];
            }
        }
    }
    int size(int p){
        return sz[root(p)];
    }
};
                

int main(void){
    int nTests;
    scanf("%d\n",&nTests);
    while(nTests--){
        int F, nFriends=0;
        scanf("%d\n",&F);
        map<string,int> table;
        unionfind UF(F*2);
        for(int i = 0; i < F; i++){
            char s1[21],s2[21];
            int p,q;
            scanf("%s %s\n",s1,s2);
            string a = s1, b = s2;
            if(table.count(a)>0){
                p = table[a];
            }
            else {
                p = table[a] = nFriends++;
            }
            if(table.count(b)>0){
                q = table[b];
            }
            else{
                q = table[b] = nFriends++;
            }
            UF.unionUF(p,q);
            cout << UF.size(p) << endl;
        }
    }
    return 0;
}
