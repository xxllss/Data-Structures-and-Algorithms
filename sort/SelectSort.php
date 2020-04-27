<?php

function selectSort(&$arr){
    $length = count($arr);

    for($i=0;$i<$length-1;$i++){
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

$arr = [9,5,8,3,7,4,6,2];
selectSort($arr);
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
