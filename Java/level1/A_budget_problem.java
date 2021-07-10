  
/*
---------------------------------------------
A_budget_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12982?language=java
---------------------------------------------
*/

import java.util.Arrays;

class Solution {
    public int solution(int[] d, int budget) {
        int i, sum;
        for(i = 0, sum = 0, Arrays.sort(d); i <d.length && sum + d[i] <= budget; sum += d[i++]);
        return i;
    }
}
