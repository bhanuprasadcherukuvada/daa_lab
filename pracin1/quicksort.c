#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
	int temp = *a;
	 *a = *b;
	 *b = temp;
}	
int partition(int ar[], int l,int r){
	int x = ar[r];
	int p = l-1;
	for(int i = l;i<r;i++){
		if(ar[i] < x){
			p = p +1;
			swap(&ar[p],&ar[i]);
		}
	}
	swap(&ar[p+1],&ar[r]);
	return p+1;
}

void quicksort(int ar[],int l,int r){
	if(l < r){
		int p = partition(ar,l,r);
		quicksort(ar,l,p-1);
		quicksort(ar,p+1,r);
	}
}

void main(){
	int arr[100];
	int n;
	scanf("%d",&n);
	for(int i =0;i<n;i++)
		scanf("%d",&arr[i]);
	quicksort(arr,0,n-1);
	for(int i =0;i<n;i++)
		printf("%d\t",arr[i]);
}




