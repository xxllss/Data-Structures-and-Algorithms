#include <stdio.h>
#include <stdlib.h>
#include "create_list_graph.h"

/*
 *int main(){
 *    GraphAdjList *G;
 *    G = (GraphAdjList *)malloc(sizeof(GraphAdjList));
 *    createAdjGraph(G);
 *    return EXIT_SUCCESS;
 *}
 */

//邻接表创建图
void createAdjGraph(GraphAdjList *G){
    int i,j,k,w;
    char ch;//仅用作过滤每次输入的换行
    printf("input the number of vertices and edges:\n");
    scanf("%d%d",&G->numV,&G->numE);
    ch = getchar();

    printf("input the value of each vertex:\n");
    for(i=0;i<G->numV;i++){
        scanf("%c",&G->adjlist[i].data);
        ch = getchar();
        G->adjlist[i].firstedge = NULL;
    }

    printf("input the values of (vi, vj) and the weights between them:\n");
    EdgeNode *e;
    for(k=0;k<G->numE;k++){
        scanf("%d%d%d",&i,&j,&w);
        ch = getchar();
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->weight = w;
        e->next = G->adjlist[i].firstedge;
        G->adjlist[i].firstedge=e;

        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->weight = w;
        e->next = G->adjlist[j].firstedge;
        G->adjlist[j].firstedge = e;
        printf("you input edge (%d,%d) and their weight %d\n",i,j,w);
    }

}
