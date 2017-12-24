#include <stdio.h>
#include <stdlib.h>

typedef char vtype;
typedef int etype;

#define MAXVEX 100
#define MAXEDGE 100

typedef struct EdgeNode{
    int begin,end;
    etype weight;
}EdgeNode,EdgeList[MAXEDGE];

typedef struct VertexNode{
    vtype data;
}VertexNode,AdjList[MAXVEX];

typedef struct{
    AdjList adjlist;
    EdgeList edgelist;
    int numV,numE;
}EdgeAdjGraph;
void createEdgeArrayGraph(EdgeAdjGraph *);

int main(){
    EdgeAdjGraph *G;
    G = (EdgeAdjGraph *)malloc(sizeof(EdgeAdjGraph));
    createEdgeArrayGraph(G);
    return EXIT_SUCCESS;
}

//边集数组创建图
void createEdgeArrayGraph(EdgeAdjGraph *G){
    int i,j,k,w;
    char ch;
    printf("input the number of vertexs and edges:\n");
    scanf("%d%d",&G->numV,&G->numE);
    ch = getchar();

    printf("input the value of each vertex\n");
    for(i=0;i<G->numV;i++){
        scanf("%d",G->adjlist[i].data);
        ch = getchar();
    }

    printf("input edge (vi,vj) and their weight\n");

    EdgeNode *e;
    for(k=0;k<G->numE;k++){
        scanf("%d%d%d",&i,&j,&w);
        ch = getchar();
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->begin = i;
        e->end = j;
        e->weight = w;
        printf("you input edge:(%d,%d) and their weight:%d\n",i,j,w);
    }
}
