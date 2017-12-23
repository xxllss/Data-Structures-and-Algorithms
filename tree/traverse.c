#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "common.h"

void preOrderTraverse(BiTree);
void inOrderTraverse(BiTree);
void postOrderTraverse(BiTree);


int main(){
    BiTree T;
    T = createBiTree(T);

    printf("pre order traverse start ....\n");
    preOrderTraverse(T);

    printf("in order traverse start ....\n");
    inOrderTraverse(T);

    printf("post order traverse start ....\n");
    postOrderTraverse(T);

    printf("delete BiTree start ....\n");
    deleteBiTree(T);
    return EXIT_SUCCESS;
}

/*
 *前序遍历
 */
void preOrderTraverse(BiTree T) {
    if(T==NULL) {
        return ;
    }
    printf("the node value is %c\n",T->data);
    preOrderTraverse(T->lchild);
    preOrderTraverse(T->rchild);
}

/*
 *中序遍历
 */
void inOrderTraverse(BiTree T){
    if(T == NULL){
        return;
    }
    inOrderTraverse(T->lchild);
    printf("the node value is %c\n",T->data);
    inOrderTraverse(T->rchild);
}

/*
 *后序遍历
 */
void postOrderTraverse(BiTree T){
    if(T == NULL){
        return;
    }
    postOrderTraverse(T->lchild);
    postOrderTraverse(T->rchild);
    printf("the node value is %c\n",T->data);
}

