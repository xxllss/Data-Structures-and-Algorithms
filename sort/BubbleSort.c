# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct{
    int r[10];
    int length;
} list;

typedef enum {
    FALSE,
    TRUE
} Status;

void swap(list *l,int i,int j){
    int temp;
    temp = l->r[i];
    l->r[i] = l->r[j];
    l->r[j] = temp;
}
void print_list(list *l){
    int i=0;
    for(i=0;i<=9;i++){
        printf("l->r[%d] = %d\n",i,l->r[i]);
    }
}

void bubbleSort1(list *l){
    int i,j;
    //i 只能到 前一位
    for(i=0;i<l->length;i++){
        //j能到最后一位
        for(j=i+1;j<=l->length;j++){
            if(l->r[i]>l->r[j]){
                swap(l,i,j);
            }
        }
    }
}

void bubbleSort2(list *l){
    int i,j,temp;
    Status flag = TRUE;
    for(i=1;i<l->length && flag==TRUE;i++){
        flag = FALSE;
        for(j=l->length-1;j>=i;j--){
            if(l->r[j] > l->r[j+1]){
                swap(l,j,j+1);
                flag = TRUE;
            }
        }
    }
}
int main(){
    list *l;
    l = (list*)malloc(sizeof(list));
    l->length = 9;
    int r[] ={0,50,10,90,30,70,40,80,60,20};
    memcpy(l->r,r,sizeof(l->r));
    bubbleSort2(l);
    print_list(l);
    free(l);
    return 0;
}



