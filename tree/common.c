#include <stdio.h>
#include <stdlib.h>
#include "common.h"

/*
 *前序遍历创建二叉树
 */
BiTree createBiTree(BiTree T)
{
    etype ch;
    scanf(" %c",&ch);
    if(ch == '#') {
        T=NULL;
    }
    else
    {
        T=(BiTree)malloc(sizeof(BiTNode));
        T->data=ch;
        T->lchild = createBiTree(T->lchild);
        T->rchild = createBiTree(T->rchild);
    }
    return T;
}

void deleteBiTree(BiTree T){
    if(T == NULL) {
        return;
    }
    deleteBiTree(T->lchild);
    deleteBiTree(T->rchild);
    free(T);
}
