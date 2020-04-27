<?php

function bubbleSort(&$arr){
    $length = count($arr);
    $flag = true;
    for($i=0;$i<$length-1 && $flag;$i++){
        $flag = false;
        for($j=$length-1;$j>$i;$j--){
            if($arr[$j] < $arr[$j-1]){
                list($arr[$j],$arr[$j-1]) = array($arr[$j-1],$arr[$j]);
                $flag = true;
            }
        }
    }
}

$arr = [9,5,8,3,7,4,6,2];
bubbleSort($arr);
print_r($arr);
/*
 * 输出：
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
 *
 */

