#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
	
	int vertex;
	int wt;
	struct node *link;

}graph;


graph *g[50];


int parent[50];

int key[50];

int mstSet[50] = {0};


void insert(int u,int v,int w){

	graph *p = (graph *)malloc(sizeof(graph));

	p->vertex = v;

	p->wt = w;

	p->link = g[u];
	g[u] = p;

}




int minkey(int v){

	int min = INT_MAX;
	int min_index;

	for(int i=0;i<v;i++){

		if(!mstSet[i] && key[i] < min){
			
			min = key[i];
			min_index = i;
		}
	}

	return min_index;
}


	
int main(){

	int vertices,edges;
	int src,des,wt;

	int u;

	

	scanf("%d %d",&vertices,&edges);

	for(int i=0;i<vertices;i++)
		g[i] = NULL;

	for(int i =0;i< edges;i++){

		scanf("%d %d %d",&src,&des,&wt);

		insert(src,des,wt);

	}


	for(int i =0;i<vertices;i++){
		parent[i] = -1;
		key[i] = INT_MAX;
	}


	for(int i =0;i<vertices;i++){

		graph *p = g[i];

		while(p){

			printf("\n%d -> %d  weight %d\n",i,p->vertex,p->wt);

			p = p->link;
		}
	}



	mstSet[0] = 0;
      
         key[0] = 0;


	 for(int i=0;i<vertices -1;i++){


		 u = minkey(vertices);

		// printf("\n%d min index\n",u);


    		graph *p = g[u];

		 while(p){

			// printf("\nhello\n");
			 //printf("\n %d %d %d\n",p->vertex,key[p->vertex],parent[p->vertex]);


			 if( !mstSet[p->vertex] && p->wt < key[p->vertex]){

				 key[p->vertex] = p ->wt;
				 parent[p->vertex] = u;

				// printf("%d %d %d", p->vertex, key[p->vertex],parent[p->vertex]);
			 }
			 p = p->link;
		 }

		 mstSet[u] = 1;
	 }



	 for(int i=0;i<vertices;i++){

		 printf("\n%d %d %d\n",i,parent[i],key[i]);
	 }

}





