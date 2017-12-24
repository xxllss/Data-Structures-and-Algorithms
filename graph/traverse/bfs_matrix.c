#include <stdio.h>
#include <stdlib.h>
#include "../create/create_matrix_graph.h"
#include "quene.h"

void bfsTraverse(MGraph *);

int main(){
    MGraph *G;
    G = (MGraph *)malloc(sizeof(MGraph));
    createAdjGraph(G);
    bfsTraverse(G);
    return EXIT_SUCCESS;
}


//邻接矩阵层序遍历
void bfsTraverse(MGraph *G){
    int i,j;
    for(i=0;i<G->numV;i++){
        visited[i] = FALSE;
    }
    Quene *Q;
    Q = (Quene *)malloc(sizeof(Quene));
    InitQuene(Q);
    for(i=0;i<G->numV;i++){
        if(!visited[i]){
            visited[i] = TRUE;
            printf("%c ",G->vertex[i]);
            EnQuene(Q,i);
            while(!EmptyQuene(Q)){
                DeQuene(Q,i);
                for(j=0;j<G->numV;j++){
                    if(G->arc[i][j]!=INIFITY && !visited[j]){
                        visited[j] = TRUE;
                        printf("%c ",G->vertex[j]);
                        EnQuene(Q,j);
                    }
                }
            }
        }
    }
}

