#include<stdio.h>
#include<stdlib.h>
typedef struct minmax{
	int min;
	int max;
}minmax;

int mini(int a ,int b){
	return a<b?a:b;
}
int maxi(int a,int b){
	return a>b?a:b;
}

minmax minMax(int ar[],int l,int r){
	minmax mm;
	if(l == r){ mm.min = mm.max = ar[l];
	 return mm;
	}

	if(l == r-1){
		mm.min = mini(ar[l],ar[r]);
		mm.max = maxi(ar[l],ar[r]);
		return mm;
	}

	if(l< r){
		int mid = (l+r)/2;
		minmax left = minMax(ar,l,mid);
		minmax right = minMax(ar,mid+1,r);
		mm.min = mini(left.min,right.min);
		mm.max = maxi(left.max,right.max);
		return mm;
	}
}

void main(){

	minmax k;
	int arr[] = {3,4,5,1,6,2,8,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	k = minMax(arr,0,n-1);
	printf("%d %d",k.min,k.max);
}




