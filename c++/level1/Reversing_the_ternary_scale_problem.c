/*
---------------------------------------------
Reversing_the_ternary_scale_problem
from : https://programmers.co.kr/learn/courses/30/lessons/68935
---------------------------------------------
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0, size = 0, k, i;
    for(k = 1; n / k > 0; size++, k *= 3);
    int* result = (int*)malloc(sizeof(int)*size);
    
    for(i = size - 1, k/= 3; k >=1; result[i] = n / k, n -= k*result[i], k/=3, i--);    
    for(i = size - 1, k = 1; i >= 0; answer += result[i]*k, k *= 3, i--);
    return answer;
}
