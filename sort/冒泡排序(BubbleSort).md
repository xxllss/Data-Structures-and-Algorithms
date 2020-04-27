# Bubble Sort

## 基础结构

    typedef struct{
        int r[10];
        int length;
    } list;
    
    typedef enum {
        FALSE,
        TRUE
    } Status;
    
## 冒泡排序1：

    void bubbleSort_1(list *l){
        int i,j;
        //i到长度的前一位
        for(i=0;i<l->length;i++){
            //j能到最后一位
            for(j=i+1;j<=l->length;j++){
                if(l->r[i]>l->r[j]){
                    swap(l,i,j);
                }
            }
        }
    }

### 两个问题：

1. 浪费了大部分循环
1. 有些交换是无用的
![冒泡排序]https://github.com/xxllss/Data-Structures-and-Algorithms/blob/master/image/BubbleSort.png)

## 冒泡排序2:

    void bubbleSort2(list *l){
        int i,j,temp;
        Status flag = TRUE;
        //i是循环次数
        for(i=1;i<l->length && flag==TRUE;i++){
            flag = FALSE;
            //j 和 j+1 是用于数据比较
            for(j=l->length-1;j>=i;j--){
                if(l->r[j] > l->r[j+1]){
                    swap(l,j,j+1);
                    flag = TRUE;
                }
            }
        }
    }


## 关键点：

1. 顺序调整：从最后一个元素，与倒数第二个元素，倒数第二个元素与倒数第三个元素，这样依次向上冒泡比较
2. 添加flag,用于如果某次循环之后完全没有交换，则代表数据已经有序，不需要再进行排序。
