#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
	int src,des,wt;
}edge;

typedef struct sub{
	int parent;
	int rank;
}sub;

sub subset[100];

edge el[100];
edge res[100];

int comp(const void *a,const void *b){
	edge *a1 = (edge *)a;
	edge *b1 = (edge *)b;
	return a1->wt > b1->wt;
}

int find(int u){
	while(subset[u].parent != u){
		u = (subset[u].parent);
	}
	return u;
}

void union1(int u,int v){
	int x = find(u);
	int y = find(v);
	if(subset[x].rank < subset[y].rank)
		subset[x].parent = y;
	else if(subset[x].rank > subset[y].rank)
		subset[y].parent = x;
	else{
		subset[x].parent = y;
		subset[y].rank++;
	}
}

void main(){
	int v,e;
	scanf("%d %d",&v,&e);
	for(int i =0;i<e;i++)
		scanf("%d %d %d",&(el[i].src),&(el[i].des),&(el[i].wt));
	qsort(el,e,sizeof(el[0]),comp);
//	for(int i =0;i<e;i++)
	//	printf("%d %d %d\n",el[i].src,el[i].des,el[i].wt);
	for(int i =0;i<v;i++){
		subset[i].parent =i;
		subset[i].rank =0;
	}
	int m=0,n=0;
	while(m<v-1 && n< e){
		int x = find(el[n].src);
		int y = find(el[n].des);
		if(x != y){
			union1(el[n].src,el[n].des);
			res[m++] =el[n];
		}
		n++;
	}
	for(int i =0;i<v-1;i++)
		printf("%d %d %d\n",res[i].src,res[i].des,res[i].wt);
}


