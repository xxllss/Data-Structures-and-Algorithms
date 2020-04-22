# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct{
    int r[10];
    int length;
} list;

void swap(list *l,int i,int j){
    int temp;
    temp = l->r[i];
    l->r[i] = l->r[j];
    l->r[j] = temp;
}
void print_heap(list *l){
    int i=0;
    for(i=0;i<=9;i++){
        printf("l->r[%d] = %d\n",i,l->r[i]);
    }
}

void heapAdjust(list *l,int s,int m){
    int temp,j;
    temp = l->r[s];

    for(j=2*s;j<=m;j*=2){//j = 2*s 是因为s的字节点是2*s 和 2*s +1；j*=2没什么用，整个循环并没有用到j自身的增加
        if(j == m){ //只有一个子结点
            goto ONE;
        }
        if(l->r[j] < l->r[j+1]){ //寻找最大的子元素
            ++j;
        }
ONE:
        if(temp > l->r[j]){ //不用替换，本身就是大顶堆
            break;
        }
        l->r[s] = l->r[j]; //交换大元素到父节点
        s=j;  //这里很关键：只有已经交换的子元素才进行重新构造，是因为没有交换的子元素是一个完整的大顶堆
    }
    l->r[s] = temp; //将tmp元素插入到最后一个被移动的元素上
}

int getMid(int length){
    int mid;
    if(length % 2 == 1){
        mid = (length - 1) / 2;
    }else{
        mid = length/2;
    }
    return mid;
}

void heapSort(list *l){
    int i,mid;
    printf("l->length is %d\n",l->length);
    mid = getMid(l->length);

    for(i = mid;i>0;i--){
        //从最大的非叶子结点开始
        heapAdjust(l,i,l->length);
    }
    int j;
    for(i=l->length;i>1;i--){
        swap(l,1,i);
        mid = getMid(i-1);
        for(j = mid;j>0;j--){
            heapAdjust(l,j,i-1);
        }
    }
}

int main(){
    list *l;
    l = (list*)malloc(sizeof(list));
    l->length = 9;
    int r[] ={0,50,10,90,30,70,40,80,60,20};
    memcpy(l->r,r,sizeof(l->r));
    heapSort(l);
    print_heap(l);

    return 0;
}
