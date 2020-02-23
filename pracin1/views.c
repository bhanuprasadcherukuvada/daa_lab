#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct node{
	int data;
	struct node *lc;
	struct node *rc;
}node;


node *root = NULL;

int size = 0;

node* queue[100];

int front = -1;
int rear = -1;

int qmt(){
	if(front == -1)
		return 1;
	else 
		return 0;
}

int qfull(){
	if(front == (rear +1)%max)
		return 1;
	else 
		return 0;
}


void enq(node * n){
	if(qmt()){
		front = 0;
		rear = (rear +1)%max;
		queue[rear] = n;
	}
	else{
		rear = (rear + 1)%max;
		queue[rear] = n;
	}
	size++;
}


node* deq(){
	node* x;
	if(front == -1)
		exit(1);
	if(front == rear){
		x = queue[front];
		front = rear = -1;
	}
	else{
		x = queue[front];
		front = (front + 1)%max;
	}
	size--;
	return x;
}

void insert(int n){
	node *p = root;
	node *pp = NULL;
	while(p){
		pp = p;
		if(p->data < n){
			p = p -> rc;
		}
		else if(p->data > n){
			p = p ->lc;
		}
		else{
			exit(1);
		}
	}

	node *temp = (node *)malloc(sizeof(node));
	temp->data = n;
	temp->lc = NULL;
	temp->rc = NULL;

	if(!pp){
		root = temp;
	}
	else if(pp->data < n){
		pp->rc = temp;
	}
	else {
		pp->lc = temp;
	}
}



void inorder(node *p){
	if(!p)
		return;
	else{
		inorder(p->lc);
		printf("%d \t ",p->data);
		inorder(p->rc);
	}
}


void levelorder(node *p){
	int nodecnt =0;
	node* x;
	int insize;
	enq(p);
	while(!qmt()){
		nodecnt = size;
		insize = nodecnt;
		//printf("%d\n",size);
		printf("\n");
		while( nodecnt > 0){
			x = deq();
			//printf("%d\n",nodecnt);
			if(nodecnt == 1){//right view
				//nodecnt == insize for left view 
			printf("%d \t",x->data);
			}
			if(x->lc != NULL){
				enq(x->lc);
			}
			if(x->rc !=NULL){
				enq(x->rc);
			}
			nodecnt--;
		}
		printf("\n");

	}
}

void main(){
	insert(20);
	insert(8);
	insert(22);
	insert(4);
	insert(12);
	insert(10);
	insert(14);
	inorder(root);
	levelorder(root);
}




		

