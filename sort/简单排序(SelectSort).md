# 简单排序

## SelectSort.c

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
    
## SelectSort.php

    function selectSort(&$arr){
        $length = count($arr);
    
        for($i=0;$i<$length;$i++){
            $min = $i;
            for($j=$i+1;$j<$length;$j++){
                if($arr[$min] > $arr[$j]){
                    $min = $j;
                }
            }
            if($min != $j)
            {
                list($arr[$min],$arr[$i]) = array($arr[$i],$arr[$min]);
            }
        }
    }

## 说明
1.  在冒泡排序的基础上进行了改进，一次比较完成后，找到最合适的位置再进行交换；
1.  每次都将当前最小的值交换到前面。