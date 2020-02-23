#include<stdio.h>
#include<stdlib.h>
typedef enum{white,grey,black}color;
color visited[50] = {white};
int topo[50];
int size =0;
typedef struct node{
	int vertex;
	struct node *link;
}node;
node *g[50];
void insert(int u,int v){
	node *temp = (node *)malloc(sizeof(node));
	temp->vertex = v;
	temp->link = NULL;
	temp->link = g[u];
	g[u] = temp;
}

int dfsutil(int u){
	visited[u] = grey;
	node *p = g[u];
	while(p){
		if(visited[p->vertex] == grey){
			return 1;
		}
		if(visited[p->vertex] == white){
			if(dfsutil(p->vertex))
					return 1;
		}
		p = p->link;
	}
	visited[u] = black;
	topo[size++] = u;
	return 0;
}

void main(){
	int v,e,m,n;
	scanf("%d %d",&v,&e);
	for(int i =0;i<v;i++)
		g[i] = NULL;
	for(int i =0;i<e;i++){
		scanf("%d %d",&m,&n);
		insert(m,n);
	}

	for(int i =0;i<v;i++){
		if(visited[i] == white){
			if(dfsutil(i)){
				printf("cycle detected");
				return;
			}
		}
	}
	for(int i =size-1;i>=0;i--)
		printf("%d\t",topo[i]);
}







