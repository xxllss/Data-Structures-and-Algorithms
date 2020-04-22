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

int partition(list *l,int low,int high){
    int pivotValue;
    pivotValue = l->r[low];
    while(low<high){
        while(low<high && l->r[high] > pivotValue){
            --high;
        }
        if(low != high){
            swap(l,low,high);
        }
        while(low<high && l->r[low] < pivotValue){
            ++low;
        }
        if(low != high){
            swap(l,low,high);
        }
    }
    //return low; 这里low 和high 相等，都指向当前pivot 都位置
    return high;
}
static void Qsort(list *l,int low,int high){
    int pivot;//枢纽，中间的意思,以此值来划分左右值
    if(low < high){    /* low和high在patition中更改*/
        pivot = partition(l,low,high);
        Qsort(l,1,pivot-1);
        Qsort(l,pivot+1,high);
    }
}
void quickSort(list *l){
    Qsort(l,1,l->length);
}


int main(){
    list *l;
    l = (list*)malloc(sizeof(list));
    l->length = 9;
    int r[] ={0,50,10,90,30,70,40,80,60,20};
    memcpy(l->r,r,sizeof(l->r));
    quickSort(l);
    print_heap(l);
    free(l);
    return 0;
}
