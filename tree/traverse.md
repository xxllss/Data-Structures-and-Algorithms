# 二叉树遍历

前序遍历顺序：根节点->左结点->右结点

中序遍历顺序：左结点->根节点->右结点

后序遍历顺序：左结点->右结点->根节点

层序遍历顺序：从上到下,从左到右。

说明：该二叉树通过前序遍历进行创建,用到了链表的头结点。

## 文件说明

1.common.c 创建、删除二叉树

2.traverse.c 包含前序遍历、中序遍历、后续遍历实现

3.level_order_traverse.c 层序遍历算法实现

## 二叉树的创建

![二叉树](https://i.imgur.com/sMiazYW.png)

>按照前序遍历创建的顺序为：ABD##E##CF###
>
>前序遍历: A B D E C F
>
>中序遍历：D B E A F C
>
>后续遍历：D E B F C A
>
>层序遍历：A B C D E F

---
#层序遍历

## 编译

    gcc -o build level_order_traverse.c common.c

## 运行

    ./build
    ABDHP##Q##IR##S##EJT##U##KV##W##CFLX##Y##MZ###GN##O##
    A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

## valgrind内存检测

    [root@localhost app]# valgrind --leak-check=full ./build
    ==32923== Memcheck, a memory error detector
    ==32923== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
    ==32923== Using Valgrind-3.12.0 and LibVEX; rerun with -h for copyright info
    ==32923== Command: ./build
    ==32923==
    ABDHP##Q##IR##S##EJT##U##KV##W##CFLX##Y##MZ###GN##O##
    A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
    ==32923==
    ==32923== HEAP SUMMARY:
    ==32923==     in use at exit: 0 bytes in 0 blocks
    ==32923==   total heap usage: 54 allocs, 54 frees, 1,072 bytes allocated
    ==32923==
    ==32923== All heap blocks were freed -- no leaks are possible
    ==32923==
    ==32923== For counts of detected and suppressed errors, rerun with: -v
    ==32923== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

## 参考

《大话数据结构》

[二叉树的层序遍历](https://www.cnblogs.com/chen-cai/p/7821860.html )

[二叉树的遍历-维基百科](https://zh.wikipedia.org/wiki/%E6%A0%91%E7%9A%84%E9%81%8D%E5%8E%86)
