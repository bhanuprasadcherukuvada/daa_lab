#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int pid;
	int pft;
	int dl;
	int served;
}node;
node list[100];
int min(int a ,int b){
	return a < b?a:b;
}
int comp(const void *a,const void *b){
	node *a1 = (node *)a; 
        node *a2 = (node *)b;
	return a1->pft < a2->pft;
}
void main(){
	int n,maxd,i,j,mind,sum =0;
	int ocp[100] ={0};
	scanf("%d %d",&n,&maxd);
	for(int i =0;i<n;i++){
		list[i].pid = i;
		scanf("%d %d", &(list[i].pft),&(list[i].dl));
	}
	qsort(list,n,sizeof(list[0]),comp);
	for(i =0;i<n;i++){
		mind = min(maxd,list[i].dl);
		for(j = mind-1;j>=0;j--){
			if(ocp[j] == 0){
				ocp[j] = list[i].pid;
				sum += list[i].pft;
				list[i].served = 1;
				break;
			}
		}
	}
	printf("%d",sum);
	for(i =0;i<maxd;i++)
		printf("%d\t",ocp[i]);

}



	
