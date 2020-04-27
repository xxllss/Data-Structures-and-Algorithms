<?php

function insertSort(&$arr){
    $length = count($arr);
    for($i=1;$i<$length;$i++){
        $temp = $arr[$i];
        for($j = $i-1; $arr[$j] > $temp && $j >=0;$j--){
            $arr[$j+1] = $arr[$j];
        }
        if($i != $j+1){
            $arr[$j+1] = $temp;
        }
    }
}

$arr = [9,5,8,3,7,4,6,2];
InsertSort($arr);
print_r($arr);
/*
 *Array
 *(
 *    [0] => 2
 *    [1] => 3
 *    [2] => 4
 *    [3] => 5
 *    [4] => 6
 *    [5] => 7
 *    [6] => 8
 *    [7] => 9
 *)
 */
?>
