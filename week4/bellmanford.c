#include<stdio.h>
#include<limits.h>
#include<stdlib.h>


typedef struct edge{

	int src;
	int des;
	int wt;
}edge;

edge edlist[100];

int dist[100];

int parent[100];

typedef struct node{

	int vertex;
	struct node *link;
}node;

node *g[100];


void insert(int u,int v){

	node *p = (node *)malloc(sizeof(node));

	p->vertex = v;

	p->link = g[u];

	g[u] = p;

}


void bellmanford(int v,int e){

	dist[0] = 0;
	parent[0] = -1;
	int i,j;

	for(i =0;i< v-1;i++){

		for(j = 0;j<e;j++){
			int u = edlist[j].src;
			int v = edlist[j].des;
			int wt = edlist[j].wt;

			if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){

				dist[v] = dist[u] + wt;
				parent[v] = u;
			}
		}
	}
}



void printpath(int i){

	if(parent[i] == -1){
		printf("0\t");
		return;
	}

	printpath(parent[i]);

	printf("%d\t",i);
}




void printdist(int v){

	for(int i =0;i< v ;i++){

		printf("\n 0 to %d is %d\n",i,dist[i]);
		
		printpath(i);
	}
}


void main(){

	int e,v;
	int i;

	scanf("%d %d",&v,&e);


	printf("%d %d",v,e);

	for(int i =0;i<v;i++){
		g[i] = NULL;
	}

	for(int i =0 ;i<v;i++)
		dist[i] = INT_MAX;


	for(int i =0;i<e;i++){

		scanf("%d %d %d",&edlist[i].src,&edlist[i].des,&edlist[i].wt);
		insert(edlist[i].src,edlist[i].des);
	}


	for(int i =0;i<e;i++){

		printf("\n %d %d %d\n",edlist[i].src,edlist[i].des,edlist[i].wt);
	}


	bellmanford(v,e);


	for(i = 0;i< e;i++){

		if(dist[edlist[i].src] != INT_MAX && dist[edlist[i].src] + edlist[i].wt < dist[edlist[i].des]){

				printf("\n negative edge detected,cannot apply blmfrd\n");
				return;
		}
	}

	printdist(v);


}



