#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int wt;
	int pft;
}node;

node list[100];

int comp(const void *a,const void *b){

	node *a1 = (node *)a;
	node *b1 = (node *)b;
	float m,n;
	m = (float)a1->pft/a1->wt;
	n = (float)b1->pft/b1->wt;
	return m<n;
}
void main(){

	int n;
	int cap;
	scanf("%d %d",&n,&cap);
	for(int i =0;i<n;i++){
		scanf("%d %d",&(list[i].wt),&(list[i].pft));
	}
	qsort(list,n,sizeof(list[0]),comp);
	for(int i =0;i<n;i++){
		printf("%d %d\n",list[i].wt,list[i].pft);
	}

	int i;
	float x[100];
	int m = cap;
	for(i =0;i<n;i++){
		if(m < list[i].wt) break;
		m -= list[i].wt;
		x[i] = 1;
	}
	if(i < n){
		x[i] =(float)m/list[i].wt;
	}
	float sum =0;

	for(int k =0;k<=i;k++){
		sum += list[i].pft *x[i];
	}
	printf("%.2f",sum);
}


		





