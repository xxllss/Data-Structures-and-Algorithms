#include <stdio.h>
#include <stdlib.h>

typedef char vtype;
typedef int etype;

#define MAXVEX 100

//边表结构
typedef struct EdgeNode{
    int tailvex;
    int headvex;
    etype weight;
    struct EdgeNode *headlink,*taillink;
}EdgeNode;

//顶点表结构
typedef struct VertexNode{
    vtype data;
    EdgeNode *firstin,*firstout;
}VertexNodei,AdjList[MAXVEX];

typedef struct OrthGraphList{
    AdjList adjlist;
    int numV,numE;
}OrthGraphList;

void createOrthGraph(OrthGraphList *);

int main()
{
    OrthGraphList *G;
    G = (OrthGraphList *)malloc(sizeof(OrthGraphList));
    createOrthGraph(G);
    return EXIT_SUCCESS;
}

void createOrthGraph(OrthGraphList *G){
    char ch;
    int i,j,k,w;
    printf("input vertex and edge number:\n");
    scanf("%d%d",&G->numV,&G->numE);
    ch = getchar();
    printf("input the value of each vertex:\n");
    for(i=0;i<G->numV;i++){
        scanf("%d",&G->adjlist[i].data);
        ch = getchar();
        G->adjlist[i].firstin = NULL;
        G->adjlist[i].firstout = NULL;
    }

    printf("input edge (vi,vj) and their value:\n");
    EdgeNode *e;
    for(k=0;k<G->numE;k++){
        scanf("%d%d%d",&i,&j,&w);
        ch = getchar();
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->tailvex = i;
        e->headvex = j;
        e->weight = w;
        e->taillink = G->adjlist[i].firstout;
        e->headlink = G->adjlist[j].firstin;

        G->adjlist[i].firstout=e;
        G->adjlist[j].firstin = e;

        printf("you input edge:(%d,%d) and their weight:%d\n",i,j,w);
    }
}
