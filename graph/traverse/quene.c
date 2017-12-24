#include "quene.h"

//初始化队列
void InitQuene(Quene *Q){
    Q->front = 0;
    Q->rear = 0;
}

//入队
void EnQuene(Quene *Q,int data){
    Q->data[Q->rear] = data;
    Q->rear = (Q->rear + 1) % MAXVEX;
}

//出队
void DeQuene(Quene *Q,int data){
    data = Q->data[Q->front];
    Q->front = (Q->front+1) % MAXVEX;
    Q->front = (Q->front+1) % MAXVEX;
}

//判断队列是否为空
BOOLEAN EmptyQuene(Quene *Q){
    return Q->rear = Q->front;
}
