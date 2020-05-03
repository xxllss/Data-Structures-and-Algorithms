<?php
function ShellSort(&$arr)
{
    $length = count($arr);
    $incr   = $length;
    
    do {
        $incr = floor($incr / 4) + 1;
        
        for ($i = $incr; $i < $length; $i++) {
            
            if ($arr[$i] < $arr[$i - $incr]) {
                
                $tmp = $arr[$i];
                
                for ($j = $i - $incr; $j >= 0 && $arr[$j] > $tmp; $j -= $incr) {
                    
                    $arr[$j + $incr] = $arr[$j];
                    
                }
                $arr[$j + $incr]  = $tmp;
            }
        }
    } while ($incr > 1);
}

$arr = [9,5,8,3,7,4,6,2];
ShellSort($arr);
print_r($arr);