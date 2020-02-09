#include<stdio.h>
#include<stdlib.h>

typedef struct file{
	int size;
}file;


int size;


file heap[100];

void minHeapify(int i){

	int small = i;
	int left = 2 *i +1;
	int right = 2 *i +2;

	if(left < size && heap[left].size < heap[small].size)
		small = left;
	
	if(right < size && heap[right].size < heap[small].size)
		small = right;

	if(small != i){

		file k = heap[i];
		heap[i] =heap[small];
		heap[small] = k;

		minHeapify(small);
	}
}


int parent(int i ){

	return (i-1)/2;
}


void printheap(){

	for(int i =0;i< size/2 ;i++){
		printf("\n %d\n",heap[i].size);
		if(2 *i +1 < size ){
			printf(" left %d",heap[2 *i +1].size);
		}
		if(2 *i +2 < size){
			printf(" right %d ",heap[2 * i + 2].size);
		}
	}
}


void insert( file m){

	heap[size] = m;
	size++;


	int start = size -1;

	while(start !=0 && heap[parent(start)].size > heap[start].size){

		file k = heap[parent(start)];
		heap[parent(start)] = heap[start];
		heap[start] = k;

		start = parent(start);
	}


//	printf("inserted");
}


file extractmin(){


	file temp = heap[0];
	size--;

	heap[0] = heap[size];

	minHeapify(0);

	return temp;
}

int isone(){

	if(size == 1) return 1;
	else
		return 0;
}


int optimalmerge(){

	int sum = 0;

	while(!isone()){

//		printf("\ncount");

		file f1 = extractmin();
		printf("\nf1 %d\n",f1.size);
		file f2 = extractmin();
		printf("\nf2 %d\n",f2.size);
		file f3;
		f3.size = f1.size + f2.size;
		sum += f3.size;
		//printf("\n%d\n",f3.size);
		insert(f3);
	}

//	printf("%d",heap[0].size);

	return sum;
}


void main(){

	int n;
	int i;
	file p;

	scanf("%d",&n);

	for(i =0;i<n;i++){
		scanf("%d",&(p.size));
		insert(p);
	}

	printheap();
	int k = optimalmerge();
	printf("\n%d\n",k);
	for(int i =0;i<n;i++)
		printf(" %d ",heap[i].size);
}



		






	
