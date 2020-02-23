#include<stdio.h>
#include<stdlib.h>

typedef struct task{
	int pid;
	int start;
	int end;
}task;

task tasklist[100];

int comp(const void *a,const void *b){
	task *a1 = (task *)a;
	task *a2 = (task *)b;
	if(a1->end > a2->end)
		return 1;
	else if(a1 ->end < a2->end)
		return 0;
	else{
		return a1->start > a2->start;
	}
}

void main(){

	int n;
	int allocated[100] ={0};
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		tasklist[i].pid = i+1;
		scanf("%d %d",&(tasklist[i].start),&(tasklist[i].end));
	}
	qsort(tasklist,n,sizeof(tasklist[0]),comp);

	int i,st1 = -1,ft1 = -1,j=1,no=0;
	//allocated[0] = tasklist[0].pid;
	int count =0;
	while(no < n){
		count++;
		ft1 = -1;
	for(i =0;i<n;i++){
		if(!allocated[i] && tasklist[i].start > ft1){
			allocated[i] = tasklist[i].pid;
			no++;
			ft1 = tasklist[i].end;
			st1 = tasklist[i].start;
		}
	}
	}
	for(i =0;i<n;i++)
		printf("p%d\t",allocated[i]);
	printf("%d\n",no);
	printf("%d",count);

}

		





	
	
