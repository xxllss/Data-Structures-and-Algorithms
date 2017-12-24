typedef char vtype;
typedef int etype;
#define MAXVEX 100
#define INIFITY 65535

//邻接矩阵存储结构
typedef struct {
    vtype vertex[MAXVEX];
    etype arc[MAXVEX][MAXVEX];
    int numV,numE;//实际顶点数、边条数
}MGraph;

//创建邻接矩阵
void createAdjGraph(MGraph*);
