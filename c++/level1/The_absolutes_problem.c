/*
---------------------------------------------
The_absolutes_problem
from : https://programmers.co.kr/learn/courses/30/lessons/76501
---------------------------------------------
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// absolutes_len은 배열 absolutes의 길이입니다.
// signs_len은 배열 signs의 길이입니다.
int solution(int absolutes[], size_t absolutes_len, bool signs[], size_t signs_len) {
    int answer = 0, i, s;
    for(i = 0; i<absolutes_len; i++) {
        if(signs[i] == true)
            answer += absolutes[i];
        else
            answer -= absolutes[i];
    }
    return answer;
}
