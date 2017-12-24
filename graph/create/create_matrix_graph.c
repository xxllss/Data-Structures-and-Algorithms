#include <stdio.h>
#include <stdlib.h>
#include "create_matrix_graph.h"

/*
 *int main(){
 *    MGraph *G;
 *    G = (MGraph *)malloc(sizeof(MGraph));
 *    createAdjGraph(G);
 *    return EXIT_SUCCESS;
 *}
 */

//邻接矩阵创建图
void createAdjGraph(MGraph *G){
    int i,j,k,w;
    char ch;//用于消除缓冲区换行
    printf("input vertex and edges number:\n");
    scanf("%d%d",&G->numV,&G->numE);
    ch = getchar();
    for(i=0;i<G->numV;i++){
        for(j=0;j<G->numV;j++){
            G->arc[i][j]=INIFITY;
        }
    }

    printf("input every vertex value:\n");
    for(i=0;i<G->numV;i++){
        scanf("%c",&G->vertex[i]);
        ch = getchar();
    }

    printf("input (vi,vj) and their weight\n");
    for(k=0;k<G->numE;k++){
        scanf("%d%d%d",&i,&j,&w);
        G->arc[i][j]=w;
        G->arc[j][i]=w;
        ch = getchar();
        printf("you input edge (%d,%d) and their weight:%d\n",i,j,w);
    }
}

