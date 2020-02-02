#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int vertex;
    struct node *link;
}graph;


typedef struct edge{
    int src;
    int des;
    int wt;
}edge;


typedef struct subset{
    int parent;
    int rank;
}subset;


graph *g[50];

edge el[50];

edge result[50];

subset parent[50];


int comp(const void *a ,const void * b){

    edge a1 = *(edge*) a;
    edge b1 = *(edge*) b;

    return a1.wt > b1.wt;
}



int find(int i){
    
    while(parent[i].parent != i){
        i = parent[i].parent;
    }

    return parent[i].parent;
}

void union1(int i,int j){

    int x = find(i);
    int y = find(j);


    if(parent[x].rank > parent[y].rank){
        parent[y].parent = x;
    }

    else if(parent[y].rank > parent[x].rank){
        parent[x].parent = y;
    }
    else{

        parent[x].parent = y;

        parent[y].rank++;
    }
}



void main(){

    int k = 0;

    int vertices,edges;


    printf("enter vertices and edges count");
    scanf("%d %d",&vertices,&edges);

    for(int i =0;i<vertices;i++){
        g[i] = NULL;
    }


    for(int i =0;i<vertices;i++){
        parent[i].parent = i;
        parent[i].rank = 0;
    }

    for(int i =0 ;i<edges;i++){
        scanf("%d %d %d",&el[i].src,&el[i].des,&el[i].wt);
    }

    qsort(el,edges,sizeof(el[0]),comp);

    for(int i=0;i<edges;i++){
        printf("%d %d %d",el[i].src,el[i].des,el[i].wt);
    }


    //edge edgename = e[k];


   int e =0;
  // int k = 0;

    while(e < vertices -1 && k < edges){

        edge nextedge;

        nextedge = el[k];
        k++;


        int x = find(nextedge.src);
        int y = find(nextedge.des);

        if(x != y){


            union1(nextedge.src,nextedge.des);

            result[e++] = nextedge;
            
        }

    }


    for(int i =0;i<vertices-1;i++){
        printf("%d %d %d",result[i].src,result[i].des,result[i].wt);
    }


}
