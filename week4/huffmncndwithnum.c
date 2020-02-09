#include<stdio.h>
#include<stdlib.h>

typedef struct minHeapNode{

	char sym;
	int freq;
	struct minHeapNode *left ,*right;

}minHeapNode;


typedef struct hashtable{

	char k;
	long long int code;
}hash;

hash *h;

minHeapNode **minHeap;

int size = 0;

int array[100] = {0};

long long int  visited[100] = {0};

int n;
int counter = 0;

long long int hashfun(long long int k){

	return k/n;
}


void insert(hash m){

     long long int d = hashfun(m.code);

	if(!visited[d]){

		h[d] = m;
		visited[d ] = 1;
		return;
	}

	else{
	    long long int p = (d+1)%n;

		while(p !=  d){

			if(!visited[p]){
				h[p] = m;
				visited[p] = 1;
				return;
			}
			p = (p+1)%n;
		}
	
		printf("full");
		return;
	}
}



char search( long long int code){


	long long int k = hashfun(code);

	if( h[k].code == code)
		return h[k].k;
	else{

		long long int d = (k+1)%n;

		while(visited[d] || k != d){

			if( h[d].code == code){

				return h[d].k;
			}
		}
		printf("not found");
	}
}

void minHeapify(int i){

	int small = i;
	int left = 2 *i +1;
	int right = left +1;


	if( left < size && minHeap[left]->freq < minHeap[small]->freq)

		small = left;

	if(right < size && minHeap[right]->freq < minHeap[small]->freq)

		small = right;


	if(small != i){

		minHeapNode *temp = minHeap[small];
		minHeap[small] = minHeap[i];
		minHeap[i] = temp;

		minHeapify(small);
	}
}





int parent(int i){

	return (i-1)/2;
}

void insert(minHeapNode *a){


	minHeap[size] = a;

	size++;


	int start = size -1;

	while(start != 0 && minHeap[parent(start)]->freq > minHeap[start]->freq){


		minHeapNode *temp = minHeap[parent(start)];
		minHeap[parent(start)] = minHeap[start];
		minHeap[start] = temp;

	}
}


void buildheap(){
	
	int i;
	for(i = size/2 -1 ; i>=0;i--)
	{
		minHeapify(i);
	}

	printf("count is %d, %d",i,size/2 -1 );
}


minHeapNode * extractMin(){

	minHeapNode  *temp = minHeap[0];

	size--;

	minHeapNode *temp2 = minHeap[0];
	minHeap[0] = minHeap[size];
	minHeap[size] = temp2;
	buildheap(0);
	return temp;
}


int left(int i){

	if(2*i +1 < size )
		return 2 *i+1;
	else
		return 0;
}


int right(int i){

	if(2 *i + 2 < size)
		return 2 *i +2;
	else
		return 0;
}

int isone(){

	if(size == 1)

		return 1;
	else 
		return 0;
}

void huffmantree(){

	while(!isone()){

		minHeapNode *left = extractMin();
		minHeapNode *right = extractMin();
		
		printf("\n%c  %d \n",left->sym,left->freq);
		printf("\n %c %d \n",right->sym,right->freq);

		minHeapNode *temp = (minHeapNode *)malloc(sizeof(minHeapNode));
		temp->sym ='$';
		temp->freq = left->freq + right->freq;
		temp->left = left;
		temp->right = right;

		printf("\n created by concatenating %c %d \n",temp->sym,temp->freq);

		insert(temp);

	}
}


void printarray(char k,int top){

	int  i;

	int sum = 0;
	int pow = 1;

	for(i =0;i<top;i++){
		printf("%d \t",array[i]);

		sum += array[i]*pow;
		pow *= 10;

	}

	long long int  m = hashfun(code);

	h[m].k = k;
	h[m].code = sum;
}



void printcodes(){


	int i;

	for(i =0;i<n;i++){

		printf("\n%c in printcodes %lld\n",h[i].k,h[i].code);
	}
}



void printtree(minHeapNode * root,int top){


	if(root->left){

		array[top] = 0;
		printtree(root->left,top+1);

	}


	if(root -> right){
		array[top] = 1;
		printtree(root->right,top+1);
	}


	if( !root->right && !root->left){
		printf("\n%c\t",root->sym);
		printarray(root->sym,top);
	}

}


void printheap(){
 	
	for(int i =0;i<=size/2;i++){


		printf("\n%d\n",i);

		printf("parent %c %d  left child %c %d right %c %d\n",minHeap[i]->sym,minHeap[i]->freq,minHeap[left(i)]->sym,minHeap[left(i)]->freq,minHeap[right(i)]->sym,minHeap[right(i)]->freq);
	}

}


void preorder( minHeapNode *root){

	if(!root)
		
		return;

	printf("\n %c %d\n",root->sym,root->freq);
	preorder(root->left);
	preorder(root->right);
}

void main(){

	int i;
	minHeapNode *temp;

	h = (hash *)malloc(n*sizeof(hash));


	scanf("%d",&n);

	size = n;


	minHeap = (minHeapNode **)malloc(n *sizeof(minHeapNode*));


	for(int i =0;i<n;i++)
		minHeap[i] = NULL;


	for(i =0;i<n;i++){

		temp = (minHeapNode *)malloc(sizeof(minHeapNode));

		scanf(" %c %d",&temp->sym,&temp->freq);

		minHeap[i] = temp;

		printf("\n%c %d\n",minHeap[i]->sym,minHeap[i]->freq);

	}


	for(i =0;i<n;i++){

		temp = minHeap[i];
		temp->left = NULL;
		temp->right = NULL;

	}

	buildheap();

	printf("\n%c %d left %c %d\n",minHeap[2]->sym,minHeap[2]->freq,minHeap[5]->sym,minHeap[5]->freq);
	printheap();
	huffmantree();
	preorder(minHeap[0]);
	printtree(minHeap[0],0);
	printcodes();

}











