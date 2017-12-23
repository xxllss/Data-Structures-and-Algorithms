typedef char etype;

typedef struct BiTNode{
    etype data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree createBiTree(BiTree);
void preOrderTraverse(BiTree);
void inOrderTraverse(BiTree);
void postOrderTraverse(BiTree);
void deleteBiTree(BiTree);
