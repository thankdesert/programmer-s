  
/*
---------------------------------------------
The_claw_machine_game_problem
https://programmers.co.kr/learn/courses/30/lessons/12977
solved by using naive.
---------------------------------------------
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0, temp;
    
    for(int i = 0; i<nums_len; i++) {
        for(int j = i + 1; j<nums_len; j++) {            
            for(int k = j + 1; k < nums_len; k++) {
                temp = nums[i] + nums[j] + nums[k];
                for(int t = 2; t < temp; t++)
                    if(temp % t == 0)
                        break;
                    else if(t == temp - 1)
                        answer++;
            }
        }
    }
    
    return answer;
}
