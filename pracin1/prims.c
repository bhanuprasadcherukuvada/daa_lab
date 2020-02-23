#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node{
	int vertex;
	int wt;
	struct node *link;
}node;

int mstset[50] = {0};
int parent[50];
int keyset[50];
node *g[50];

void insert(int u,int v,int w){
	node *temp =(node *)malloc(sizeof(node));
	temp->vertex = v;
	temp->wt =w;
	temp->link = NULL;
	node *k = g[u];
	temp->link = g[u];
	g[u] = temp;
}

int minkey(int v){ 
     int minval = INT_MAX;
     int minindex = -1;
	int i;
	for(i =0;i<v;i++){
		if(!mstset[i] && keyset[i] < minval){
			minval = keyset[i];
			minindex = i;
		}
	}
	return minindex;
}

void main(){
	int v,e;
	int l,m,n;
	scanf("%d %d",&v,&e);
	for(int i =0;i<v;i++){
		g[i] = NULL;
		keyset[i] = INT_MAX;
		parent[i] = -1;
	}
	for(int i =0;i<e;i++){
		scanf("%d %d %d",&l,&m,&n);
		insert(l,m,n);
	}
	keyset[0] = 0;
	int i =0;
	while(i<v-1){
		int min = minkey(v);
		node *p = g[min];
		while(p){
			if(!mstset[p->vertex] && p->wt < keyset[p->vertex]){
				keyset[p->vertex] = p->wt;
				parent[p->vertex] = min;
			}
			p = p->link;
		}
		mstset[min] = 1;
		i++;
	}

	for(int l =0;l<v;l++)
		printf("%d %d %d\n",l,parent[l],keyset[l]);
}



