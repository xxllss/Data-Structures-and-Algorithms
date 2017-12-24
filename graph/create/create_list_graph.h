typedef char vtype;
typedef int etype;

#define MAXVEX 100

typedef struct  EdgeNode{
    int adjvex;
    etype weight;
    struct EdgeNode *next;
}EdgeNode;

typedef struct{
    vtype data;
    EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct{
    AdjList adjlist;
    int numV,numE;
}GraphAdjList;
void createAdjGraph(GraphAdjList *);
