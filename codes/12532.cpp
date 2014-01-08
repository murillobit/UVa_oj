#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

void construction(int node, int start, int end, int* tree, int* array, int arraySize){
    //cout << node << endl;
    if(start==end){
		tree[node] = array[end];
	}
	else{
		construction(2*node, start, (start+end)/2, tree, array, arraySize);
		construction(2*node +1, (start+end)/2 +1, end, tree, array, arraySize);

		tree[node] = tree[2*node]*tree[2*node+1];
	}
}
void update(int modified, int node, int start, int end, int* tree, int* array, int arraySize){
	if(start==end){
		tree[node] = array[end];
	}
	else{
		if(modified <= (start+end)/2){
			update(modified,2*node,start,(start+end)/2,tree,array, arraySize);
		}
		else{
			update(modified,2*node+1,(start+end)/2+1,end,tree,array, arraySize);
		}
		tree[node] = tree[2*node] * tree[2*node+1];
	}
}
int query(int node, int start, int end, int* tree, int* array, int arraySize, int qStart, int qEnd){
	int p1,p2;
	if(qStart > end || qEnd < start)
		return -10;

	if(start >= qStart && end <= qEnd)
		return tree[node];

	p1 = query(2*node, start, (start+end)/2, tree, array, arraySize, qStart, qEnd);
	p2 = query(2*node+1, (start+end)/2 +1, end, tree, array, arraySize, qStart, qEnd);

	if(p1==-10) return p2;
	if(p2==-10) return p1;
	return p1*p2;
}

int main(){
	while(!feof(stdin)){
		int n,k;
		scanf("%d %d\n",&n,&k);
        //printf("%d %d\n",n,k);
		//int numbers[100000], tree[300000];
		int numbers[100000], tree[300000];
		for(int i = 0; i < n; i++){
			int e;
			scanf("%d ", &e);
//			cout << i << endl;
			numbers[i]  = ( e > 0? 1 : (e < 0? -1 : 0));
		}
		

		construction(1,0,n-1,tree,numbers,n);

		for(int i = 0; i < k; i++){
			char c;
			int a,b;
			scanf("%c %d %d\n",&c,&a,&b);
//			printf("%c %d %d\n",c,a,b);
			if(c=='P'){
				a--; b--;
				int res =  query(1,0,n-1,tree,numbers,n,a,b);
				cout << (res>0 ? '+' : res<0? '-' : '0');
			}
			else if(c == 'C'){
				a--;
				numbers[a] = ( b > 0? 1 : (b < 0? -1 : 0));
				update(a,1,0,n-1,tree,numbers,n);
			}
		}
		cout << endl;
	}
	return 0;
}
