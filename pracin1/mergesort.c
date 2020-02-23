#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int l,int m,int r){
	int n1 = m - l;
	int n2 = r-m +1;
	int *left = (int *)malloc(sizeof(int) *n1);
	int *right = (int *)malloc(sizeof(int)*n2);
	for(int i = 0;i<n1;i++)
		left[i] = arr[l+i];
	for(int i =0;i<n2;i++)
		right[i] = arr[m+i];
	int i =0,j=0,k=l;
	while(i<n1 && j<n2){
		if(left[i] < right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while(i<n1)
		arr[k++] = left[i++];
	while(j<n2)
		arr[k++] = right[j++];
}


void mergesort(int arr[],int l,int r){
	if(l<r){
		int mid = (l+r)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

void main(){
	int arr[] = {434,3245,58,75,574,4745,5745,4422,3564,76867,42252,6574};
	int n = sizeof(arr)/sizeof(arr[0]);
	mergesort(arr,0,n-1);
	for(int i =0;i<n;i++)
		printf("%d\t",arr[i]);
}
