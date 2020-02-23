#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	char sym;
	int freq;
	struct node *lc;
	struct node *rc;
}node;

node** minHeap;
int size =0;
int array[100] ={0};
char **hash;
void printarray(char c,int top){
	int i;
	hash[c -'a'] = (char *)malloc(sizeof(char)*top+1);
	for(i =0;i<top;i++){
		printf("%d\t",array[i]);
		hash[c - 'a'][i] = array[i];
	}
	hash[c-'a'][i] ='\0';	
	printf("\n");
}

void minheap(int i){
	int s =i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l <size && minHeap[l]->freq < minHeap[s]->freq)
		s = l;
	if(r<size && minHeap[r]->freq < minHeap[s]->freq)
		s = r;
	if(s!= i){
		node *temp = minHeap[s];
		minHeap[s] = minHeap[i];
		minHeap[i] = temp;
		minheap(s);
	}
}

int parent(int i){
	return (i-1)/2;
}

void insert(node *p){
//	printf("inserting %d",p->freq);
	minHeap[size] = p;
	size++;
	int start = size-1;
	while(start != 0 && minHeap[start]->freq < minHeap[parent(start)]->freq){
		node *temp = minHeap[start];
		minHeap[start] = minHeap[parent(start)];
		minHeap[parent(start)] = temp;
		start = parent(start);
	}
}

node * extractmin(){
	node *temp = minHeap[0];
	size--;
	minHeap[0] = minHeap[size];
	minheap(0);
	return temp;
}

void inorder(node *root){
	if(!root)
		return;
	inorder(root->lc);
	printf("%d %c\t",root->freq,root->sym);
	inorder(root->rc);
}

void printcodes(node *root,int top){
	if(root->lc){
		array[top] = 0;
		printcodes(root->lc,top+1);
	}
	if(root->rc){
		array[top] = 1;
		printcodes(root->rc,top+1);
	}
	if(!root->rc && !root->lc){
		printf("%c --> ",root->sym);
		printarray(root->sym,top);
	}
}


void main(){
	int n;
	char str[20] = "ffcddabe";
	scanf("%d",&n);
//	printf("hellO");
	hash = (char **)malloc(sizeof(char *)*26);
	minHeap = (node **)malloc(n*sizeof(node *));
      //	printf("hello");
	for(int i =0;i<n;i++)
		minHeap[i] = NULL;
	for(int i =0;i<n;i++){
		node *p = (node *)malloc(sizeof(node));
	//	printf("main fun");
		scanf(" %c %d",&p->sym,&p->freq);
		p->lc = NULL;
		p->rc = NULL;
		insert(p);
	}
	while(size > 1){
		node *left = extractmin();
		node *right = extractmin();
		node *temp = (node *)malloc(sizeof(node));
		temp->sym = '$';
		temp->freq = left->freq + right->freq;
		temp->lc = left;
		temp->rc = right;
		insert(temp);
	}
	node *root = minHeap[0];
	printcodes(root,0);
	int encodedarray[1000];
	int k =0;
	for(int i =0;i<strlen(str);i++){
		
		int m = strlen(hash[str[i] -'a']);
		printf("%d\n",m);
		for(int n = 0;n<m;n++){
			encodedarray[k++] = hash[str[i]-'a'][n];
		}
	}

	for(int i =0;i<k;i++)
		printf("%d ",encodedarray[i]);
}



	

