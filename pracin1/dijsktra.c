#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node{
	int vertex;
	int wt;
	struct node *link;
}node;

node *g[50];
int mstset[50] ={0};
int parent[50];
int dist[50];
void insert(int u,int v,int w){
	node *temp = (node *)malloc(sizeof(node));
	temp->vertex = v;
	temp->wt = w;
	temp->link = g[u];
	g[u] = temp;
}

int minkey(int v){
	int minval = INT_MAX;
	int minind = -1;
	for(int i =0;i<v;i++){
		if(!mstset[i] && dist[i] < minval){
			minval = dist[i];
			minind = i;
		}
	}
	return minind;
}

int parentp(int i){
	printf("\n");
	while(parent[i] != -1){
		printf("%d\t",i);
		i = parent[i];
	}
}

void main(){
	int v,e;
	int l,m,n;
	scanf("%d %d",&v,&e);
	for(int i =0;i<v;i++){
		g[i] = NULL;
		parent[i] = -1;
		dist[i] = INT_MAX;
	}
	for(int i =0;i<e;i++){
		scanf("%d %d %d",&l,&m,&n);
		insert(l,m,n);
	}
	
	int i = 0,min;
	dist[0] = 0;
	while(i<v-1){
	       min = minkey(v);
		node *p = g[min];
		mstset[min] = 1;
		while(p){
			if(!mstset[p->vertex] && dist[min] != INT_MAX && dist[min] + p->wt < dist[p->vertex]){
				dist[p->vertex] = dist[min] + p->wt;
				parent[p->vertex] = min;
			}
			p = p->link;
		}
		i++;
	}

	for(int i =0;i<v;i++){
		printf(" 0 to %d is %d\n",i,dist[i]);
		parentp(i);
	}
}



