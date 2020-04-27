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

void selectSort(list *l){
    int min,i,j;
    for(i=0;i<l->length;i++){
        min = i;
        for(j=i+1;j<=l->length;j++){
            if(l->r[min] > l->r[j]){
                min = j;
            }
        }
        if(min != i){
            swap(l,i,min);
        }
    }
}

int main(){
    list *l;
    l = (list*)malloc(sizeof(list));
    l->length = 9;
    int r[] ={0,50,10,90,30,70,40,80,60,20};
    memcpy(l->r,r,sizeof(l->r));
    selectSort(l);
    print_heap(l);

    return 0;
}
