#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int vol;
}node;

node heap[100];
int size =0;

void minheap(int i){
	int small = i;
	int left = 2*i+1;
	int right = 2*i+2;
	if(left < size && heap[left].vol < heap[small].vol)
		small = left;
	if(right <size && heap[right].vol < heap[small].vol)
		small = right;
	if(small != i){
		node k = heap[small];
		heap[small] = heap[i];
		heap[i] = k;
		minheap(small);
	}
}

int parent(int i){
	return (i-1)/2;
}

void insert(node k){
	heap[size] = k;
	size++;
	int start = size -1;
	while(start!=0 && heap[start].vol < heap[parent(start)].vol){
		node temp = heap[start];
		heap[start] = heap[parent(start)];
		heap[parent(start)] = temp;
		start = parent(start);
	}
}

node extractmin(){
	node temp = heap[0];
	size--;
	heap[0] = heap[size];
	minheap(0);
	return temp;
}

void main(){
	int n;
	node m;
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d",&(m.vol));
		insert(m);
	}
	int sum =0;
	while(size > 1){
		node l = extractmin();
		node r =extractmin();
		node n;
		n.vol = l.vol + r.vol;
		sum += n.vol;
		insert(n);
	}
	printf("%d",sum);
}



