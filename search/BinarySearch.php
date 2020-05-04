<?php

include '../sort/QuickSort.php';

function BinarySearch($arr,$key)
{
    $low  = 0;
    $high = count($arr) - 1;
    while ($low <= $high){
        $mid = floor(($low+$high)/2);
        if($arr[$mid] > $key){
            $high = $mid -1;
        }else if($arr[$mid] < $key ){
            $low  = $mid +1;
        }else{
            return $mid;
        }
    }
    return 0;
}

print_r($arr);

$search_i = BinarySearch($arr,7);

echo 'search_i is ',$search_i,"\n";

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
)
search_i is 5*/