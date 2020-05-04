<?php

function HeapAdjust(&$arr,$s,$length)
{
    $tmp = $arr[$s];
    for ($i = $s * 2; $i < $length; $i *= 2) {
        if ($arr[$i] < $arr[$i + 1]) {
            ++$i;
        }
        if ($tmp > $arr[$i]) {
            break;
        }
        $arr[$s] = $arr[$i];
        
        $s = $i;
    }
    $arr[$s] = $tmp;
}

function HeapSort(&$arr)
{
    $length = count($arr);
    $step   = floor($length / 2);
    
    for ($i = $step; $i > 0; $i--) {
        HeapAdjust($arr,$i,$length);
    }
    
    for ($i = $length - 1; $i > 0; $i--) {
        list($arr[0],$arr[$i]) = array($arr[$i],$arr[0]);
        HeapAdjust($arr,0,$i - 1);
    }
}

$arr = [9,5,8,3,7,4,6,2];
HeapSort($arr);
print_r($arr);