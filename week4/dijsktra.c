#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{

	int vertex;
	int wt;
struct node *link;
}node;


int parent[50];

int dist[50];

int mstSet[50] = {0};

node *g[50];

void insert(int u,int v,int w){


	node *p = (node *)malloc(sizeof(node));

	p->vertex = v;

	p->wt = w;

	p->link = g[u];
	
	g[u] = p;
}



void printpath(int j){

	if( parent[j] == -1){
		return;
	}

	else{
		printpath(parent[j]);

		printf("%d ",j);
	}
}



int mindistance(int v){


	int min = INT_MAX;
	int min_index;


	for(int i =0;i<v;i++){

		if(!mstSet[i] && dist[i] < min){

			min = dist[i];
			min_index = i;
		}
	}

	return min_index;
}





void main(){


	int vertices,edges;
	int u,v,w;


	scanf("%d %d",&vertices,&edges);

	for(int i =0;i<vertices;i++)
		g[i] = NULL;

	for(int i = 0;i<edges;i++){

		scanf("%d %d %d",&u,&v,&w);
		insert(u,v,w);
	}


	for(int i =0;i<vertices;i++){

		node *p = g[i];

		while(p){

			printf("\n%d -> %d weight %d\n",i,p->vertex,p->wt);
			p = p->link;
		}
	}


	for(int i =0;i<vertices;i++){

		parent[i] = -1;
		dist[i] = INT_MAX;
	}



	mstSet[0] = 0;
	dist[0] = 0;


	for(int i =0;i<vertices -1;i++){


		u = mindistance(vertices);


		node *p = g[u];

		while(p){

			if(!mstSet[p->vertex] && dist[u] + p->wt < dist[p->vertex]){

				dist[p->vertex] = dist[u] + p->wt;
				parent[p->vertex] = u;
			}

			p = p->link;
		}

		mstSet[u] = 1;
	}



	for(int i =0;i<vertices;i++){

		printf(" \n0 to  %d -> %d  ---->path 0 ",i,dist[i]);
		printpath(i);
		printf("\n");
	}


}





