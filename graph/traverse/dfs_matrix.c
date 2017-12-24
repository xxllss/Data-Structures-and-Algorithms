#include <stdio.h>
#include <stdlib.h>
#include "../create/create_matrix_graph.h" /** 创建邻接矩阵头文件 */

typedef enum{
    FALSE,
    TRUE
}BOOLEAN;

BOOLEAN visited[MAXVEX];

void dfs(MGraph *,int);
void dfsTraverse(MGraph *);

int main(){
    MGraph *G;
    G = (MGraph *)malloc(sizeof(MGraph));
    createAdjGraph(G);
    dfsTraverse(G);
    return EXIT_SUCCESS;
}

void dfsTraverse(MGraph *G){
    int i,j;
    for(i=0;i<G->numV;i++){
        visited[i] = FALSE;
    }

    for(i=0;i<G->numV;i++){
        if(!visited[i]){
            dfs(G,i);
        }
    }
}

void dfs(MGraph *G,int i){
    int j;
    visited[i] = TRUE;
    printf("%c ",G->vertex[i]);
    for(j=0;j<G->numV;j++){
        if(!visited[j] && G->arc[i][j] != INIFITY){
            dfs(G,j);
        }
    }
}
