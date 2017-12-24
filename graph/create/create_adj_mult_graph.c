#include <stdio.h>
#include <stdlib.h>

typedef char vtype;
typedef int etype;

#define MAXVEX 100

typedef struct EdgeNode{
    int ivex,jvex;
    etype weight;
    struct EdgeNode *ilink,*jlink;
}EdgeNode;


typedef struct VertexNode{
    vtype data;
    EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];


typedef struct MultAdjGraph{
    AdjList adjlist;
    int numV,numE;
}MultAdjGraph;

void createMultGraph(MultAdjGraph *);

int main(){
    MultAdjGraph *G;
    G = (MultAdjGraph *)malloc(sizeof(MultAdjGraph));
    createMultGraph(G);
    return EXIT_SUCCESS;
}

void createMultGraph(MultAdjGraph *G){
    int i,j,k,w;
    char ch;
    printf("input the number of  vertexs and edges:\n");
    scanf("%d%d",&G->numV,&G->numE);

    printf("input the value of each vertex:\n");
    for(i=0;i<G->numV;i++){
        scanf("%c",&G->adjlist[i].data);
        ch = getchar();
    }

    printf("input edge (vi,vj) and their weight:\n");
    EdgeNode *e;
    for(k=0;k<G->numE;k++){
        scanf("%d%d%d",&i,&j,&w);
        ch = getchar();
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->ivex = i;
        e->jvex = j;
        e->weight = w;
        e->ilink = G->adjlist[i].firstedge;
        e->jlink = G->adjlist[j].firstedge;
        G->adjlist[i].firstedge = e;
        G->adjlist[j].firstedge = e;
        printf("you input edege:(%d,%d) and their weight:%d\n",i,j,w);
    }
}
