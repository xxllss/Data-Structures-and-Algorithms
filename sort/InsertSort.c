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

void insertSort(list *l){
    int temp,i,j;
    for(i=1;i<=l->length;i++){
        temp = l->r[i];
        for(j=i-1;l->r[j] > temp;j--){
             l->r[j+1] = l->r[j];
        }
        if(j+1 != i){
            l->r[j+1] = temp;
        }
    }
}

int main(){
    list *l;
    l = (list*)malloc(sizeof(list));
    l->length = 9;
    int r[] ={0,50,10,90,30,70,40,80,60,20};
    memcpy(l->r,r,sizeof(l->r));
    insertSort(l);
    print_heap(l);

    return 0;
}
