#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef char etype;
typedef int status;

typedef struct Quene{
    BiTree t;
    struct Quene *next;
}Quene,*bQuene;

typedef struct Point{
    bQuene head,tail;
}Point,*bPoint;

void levelOrderBiTree(BiTree);
void push(bPoint,BiTree);
BiTree pop(bPoint);

int main(){
    BiTree T;
    T = createBiTree(T);
    levelOrderBiTree(T);
    deleteBiTree(T);
    return EXIT_SUCCESS;
}

void levelOrderBiTree(BiTree T){
    bQuene q;
    q = (bQuene)malloc(sizeof(Quene));
    q->t = NULL;
    q->next = NULL;

    bPoint p;
    p = (bPoint)malloc(sizeof(Point));
    p->head = q;
    p->tail = q;

    push(p,T);

    while(p->head != p->tail){
        BiTree t;
        t = pop(p);
        printf("%c ",t->data);
        if(t->lchild != NULL){
            push(p,t->lchild);
        }
        if(t->rchild != NULL){
            push(p,t->rchild);
        }
    }
    printf("\n");
    free(q);
    free(p);
}

void push(bPoint p,BiTree T){
    bQuene tempQ;
    tempQ = (bQuene)malloc(sizeof(Quene));
    if(!tempQ){
        exit(-1);
    }
    tempQ->t = T;
    tempQ->next = NULL;
    p->tail->next = tempQ;
    p->tail = tempQ;
}

BiTree pop(bPoint p){
    bQuene tempQ;
    BiTree t;
    tempQ = p->head->next;
    t = tempQ->t;
    p->head->next = tempQ->next;
    if(p->tail == tempQ){
        p->tail = p->head;
    }
    free(tempQ);
    return t;
}

