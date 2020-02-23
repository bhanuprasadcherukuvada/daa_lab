#include<stdio.h>
#include<stdlib.h>

int arr[1000];

int **tapes;

int comp(const void *a,const void *b){

	int *a1 = (int *)a;
	int *b1 = (int *)b;

	return *a1 > *b1;
}


void storeontape(int m,int n){

	int i,j;

	for(i =0;i<m;i++){
		for(j =0;j< n;j++){
			tapes[i][j] = -1;
		}
	}

	for(i =0;i<n;i++){

		tapes[i%m][i/m] = arr[i];
	}

}





void main(){

	int n;
	int np;
	int i,j;



	scanf("%d %d",&np,&n);


	tapes = (int **)malloc(sizeof(int *));

	for(int i =0;i< np;i++){
		tapes[i] = (int *)malloc(sizeof(int)*1000);
	}


	for(int i =0;i< n;i++)
		scanf("%d",&arr[i]);

	qsort(arr,n,sizeof(arr[0]),comp);

	for(int i =0;i<n;i++)
		printf("%d\t",arr[i]);

	storeontape(np,n);

	for(i =0;i<np;i++){

		int accesstime = 0;
		int sum = 0;
		int cnt =0;

	//	printf("%d",n/np);
	

		printf("\n");


		for(j =0;j< n/np + 1;j++){

			if(tapes[i][j] != -1){

				printf("%d\t",tapes[i][j]);

				accesstime += sum + tapes[i][j];
				sum += tapes[i][j];
				cnt++;
				//printf("\n access time is -> %d\n",accesstime);
			}
		//	printf("\t%.2f",(float)accesstime/cnt);
        	}



		printf("\n%.2f\n",(float)accesstime/cnt);


		printf("\n");
	}
}



