<?php

function swap(&$arr,$i,$j)
{
    list($arr[$i],$arr[$j]) = array($arr[$j],$arr[$i]);
}

function Partition(&$arr,$low,$high)
{
    $pivotValue = $arr[$low];
    while ($low < $high) {
        //一直找到小于$pivotValue的key
        while ($pivotValue <= $arr[$high] && $low < $high) {
            --$high;
        }
        if ($low < $high) {
            swap($arr,$low,$high);
        }
        
        //一直找到大于pivotValue的key
        while ($pivotValue >= $arr[$low] && $low < $high) {
            ++$low;
        }
        
        if ($low < $high) {
            swap($arr,$low,$high);
        }
    }
    //此时$low 和 $high 值一样，代表分割的枢纽所在的key值
    return $high;
}

function Qsort(&$arr,$low,$high)
{
    if ($low < $high) {
        $pivot = Partition($arr,$low,$high);
        Qsort($arr,0,$pivot - 1);
        Qsort($arr,$pivot + 1,$high);
    }
}

function QuickSort(&$arr)
{
    Qsort($arr,0,count($arr) - 1);
}

$arr = [9,5,8,3,7,4,6,2];
QuickSort($arr);
print_r($arr);
/*Array
(
    [0] => 2
    [1] => 3
    [2] => 4
    [3] => 5
    [4] => 6
    [5] => 7
    [6] => 8
    [7] => 9
)*/