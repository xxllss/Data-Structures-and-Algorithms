# 插入排序


    void insertSort(list *l){
        int temp,i,j;
        for(i=1;i<=l->length;i++){
            temp = l->r[i];
            //从i-1进行递减
            for(j=i-1;l->r[j] > temp;j--){ 
                //一定是 把j 移动到j+1
                 l->r[j+1] = l->r[j];  
            }
            //最后一次会进行j--,但是不符合上面的循环条件，所以j对应的值不再大于i;
            //将i插入到j后面(也就是j+1)
            if(j+1 != i){
                l->r[j+1] = temp;
            }       
        }
    }

假设i循环到了6（选一个中间的值，这样比较好理解多次移动的时候，各值的变化）

![插入排序循环示例](https://github.com/xxllss/Data-Structures-and-Algorithms/blob/master/image/InsertSort.png)
