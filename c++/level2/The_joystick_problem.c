/*
---------------------------------------------
The_joystick_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42860
solved by the greedy algorithm.
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

int calc(char c) {
    if(c - 'A' >= 14)
        return 26 - abs(c - 'A');
    else
        return (c - 'A');
}

int calc_dist(int cur, int target, int length) {
    if(cur == -1)
        return 9999;
    if(cur >= target) {
        return abs(target - cur);
    }
    else {
        if(abs(target - cur) >= length - abs(target - cur))
            return length - abs(target - cur);
        else
            return abs(target - cur);        
    }
}

int solution(string name) {
    int i, answer = 0, count = 0, length = name.size(), cur, left, right;
    int arr[20] = {0,};
    for(i = 0; i<length; i++) {
        if(name[i] != 'A') {
            arr[i] = 1;
            count++;
        }
    }
    cur = 0;
    do{
        if(name[cur] != 'A') {
            answer += calc(name[cur]);
            arr[cur] = 0;
            count--;
        }
        if(count == 0)
            break;
        
        left = cur - 1;
        right = cur + 1;
        for(left;;left--) {
            if(left < 0)
                left = length - 1;
            if(arr[left] == 1)
                break;
        }
        for(right;;right++) {
            if(right > length) {
                right = -1;
                break;
            }
            if(arr[right] == 1)
                break;
        }
        
        if(calc_dist(cur, left, length) >= calc_dist(cur, right, length)) {
            answer += calc_dist(cur, right, length);
            cur = right;
            printf("R ");
        }
        else {
            answer += calc_dist(cur, left, length);
            cur = left;
            printf("L ");
        }
    }
    while(1);
    
    
    return answer;
}
