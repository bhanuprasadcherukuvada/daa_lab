#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct node{
	int data;
	int hd;
	struct node *lc;
	struct node *rc;
}node;

typedef struct map{
	int data;
	struct map *link;
}map;

int mini;
int maxi;

map * lt[200];
map * rt[200];

void inserter(int n,int dis){
	map *temp = (map *)malloc(sizeof(map));
	temp->data = n;
	map *k;
	if(dis < 0){
		k = lt[dis *-1];
			
	     if(lt[dis*-1]){
		while(k->link){
			k = k->link;
		}
		k->link = temp;
	}
	else{
		lt[dis*-1] = temp;
	}


	}
	else{
		k = rt[dis];
		if(rt[dis]){
			while(k->link){
				k = k->link;
			}
			k->link = temp;
		}
		else{
	 		rt[dis] = temp;
		}
	}
}

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
	p->hd = 0;
	enq(p);
	node *x;
	while(!qmt()){
			x = deq();
			inserter(x->data,x->hd);
			if(x->lc != NULL){
				x->lc->hd = x->hd -1;
				mini = x ->hd -1;

				enq(x->lc);
			}
			if(x->rc != NULL){
				x->rc->hd = x->hd +1;
				maxi = x ->hd+1;
				enq(x->rc);
			}
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
	for(int i =0;i<200;i++){
		lt[i] = NULL;
		rt[i] = NULL;
	}

	levelorder(root);
	printf("\n");

	for(int i = (mini*-1)+1;i>0;i--){
		map *k = lt[i];
		printf("%d\n",k->data);//top view
		/*
		while(k->link){
			k = k->link; bottom view
		}
		printf("%d\t",k->data);
		printf("\n");
		*/
	}

	for(int i =0;i<=maxi;i++){
		map *k = rt[i];
		printf("%d\n",k->data);//top view
		/*
		while(k->link){
			k = k->link;   for bottom view
		}
		printf("%d\t",k->data);
		*/
		printf("\n");
	}
}




		

