#include <stdio.h>
#include <stdlib.h>
#include "../create/create_list_graph.h"
#include "quene.h"

typedef char vtype;
typedef int etype;

void bfsTraverse(GraphAdjList *);

int main(){
    GraphAdjList *G;
    G = (GraphAdjList *)malloc(sizeof(GraphAdjList));
    createAdjGraph(G);
    bfsTraverse(G);
    return EXIT_SUCCESS;
}

void bfsTraverse(GraphAdjList *G){
    int i;
    Quene *Q;
    Q = (Quene *)malloc(sizeof(Quene));
    InitQuene(Q);

    for(i=0;i<G->numV;i++){
        visited[i] = FALSE;
    }
    for(i=0;i<G->numV;i++){
        if(!visited[i]){
            printf("%c ",G->adjlist[i].data);
            visited[i] = TRUE;
            EnQuene(Q,i);
            EdgeNode *e;
            while(!EmptyQuene(Q)){
                DeQuene(Q,i);
                e = G->adjlist[i].firstedge;
                while(e){
                    if(!visited[e->adjvex]){
                        printf("%c ",G->adjlist[e->adjvex]);
                        visited[e->adjvex] = TRUE;
                        EnQuene(Q,e->adjvex);
                    }
                    e = e->next;
                }
            }
        }
    }
}
