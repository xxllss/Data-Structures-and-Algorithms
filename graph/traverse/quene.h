typedef enum{
    FALSE,TRUE
}BOOLEAN;

#ifndef MAXVEX
#define MAXVEX 100
#endif

typedef int etype;
typedef char vtype;

BOOLEAN visited[MAXVEX];
typedef struct{
    etype data[MAXVEX];
    int front;
    int rear;
}Quene;

void InitQuene(Quene *);
void EnQuene(Quene *,int);
void DeQuene(Quene *,int);
BOOLEAN EmptyQuene(Quene *);
