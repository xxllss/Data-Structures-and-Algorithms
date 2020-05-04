#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//用于构建一个有序的查找表
void shellSort(list *l){
    int incr,tmp,i,j;
    incr = l->length;
    do{
        incr = incr/4 +1;
        for(i=incr;i<l->length;i++){
            if(l->r[i] < l->r[i-incr]){
                tmp = l->r[i];
                for(j=i-incr;j>=0 && tmp < l->r[j];j-=incr){
                    l->r[j+incr] = l->r[j];
                }
                l->r[j+incr] = tmp;
            }
        }
    }while(incr>1);
}

//二分查找
int binarySearch(list *l,int key){
    int low,high,mid;
    low  = 0;
    high = l->length-1;

    while(low <= high){
        mid = (low + high)/2;

        if(l->r[mid] > key){ //如果中间值大于查找值，代表数据在小的一边
            high = mid-1;
        }else if(key > l->r[mid]){ //如果中间值小于查找值，代表数据在大的一边
            low = mid +1;
        }else{ //
             return mid;
        }
    }
    return 0;
}

int main(){
    list *l;
    l = (list*)malloc(sizeof(list));
    l->length = 10;
    int r[] ={100,50,10,90,30,70,40,80,60,20};
    memcpy(l->r,r,sizeof(l->r));

    //构造顺序表
    shellSort(l);

    print_heap(l);

    int search_i;
    search_i = binarySearch(l,30);
    printf("search_i is %d\n",search_i);

    free(l);
    return 0;
}

/*
l->r[0] = 10
l->r[1] = 20
l->r[2] = 30
l->r[3] = 40
l->r[4] = 50
l->r[5] = 60
l->r[6] = 70
l->r[7] = 80
l->r[8] = 90
l->r[9] = 100
search_i is 2*/
