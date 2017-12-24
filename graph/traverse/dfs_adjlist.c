#include <stdio.h>
#include <stdlib.h>
#include "../create/create_list_graph.h"

#define MAXVEX 100

typedef enum{
    FALSE,TRUE
}BOOLEAN;

BOOLEAN visited[MAXVEX];

void dfs(GraphAdjList *,int);
void dfsTraverse(GraphAdjList *);

int main()
{
    GraphAdjList *G;
    G = (GraphAdjList *)malloc(sizeof(GraphAdjList));
    createAdjGraph(G);
    dfsTraverse(G);
    return EXIT_SUCCESS;
}

void dfs(GraphAdjList *G,int i){
    printf("%c ",G->adjlist[i].data);
    visited[i] = TRUE;
    EdgeNode *e;
    e = G->adjlist[i].firstedge;
    while(e){
        if(!visited[e->adjvex]){
            dfs(G,e->adjvex);
        }
        e= e->next;
    }

}

void dfsTraverse(GraphAdjList *G){
    int i;
    for(i=0;i<G->numV;i++){
        visited[i] = FALSE;
    }

    for(i=0;i<G->numV;i++){
        if(!visited[i]){
            dfs(G,i);
        }
    }
}
