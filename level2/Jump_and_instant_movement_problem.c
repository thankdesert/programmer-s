/*
---------------------------------------------
Jump_and_instant_movement_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12980
---------------------------------------------
*/

#include <string>

using namespace std;

int solution(int n) {
    int i, count;
    for(i = n, count = 0; i > 0; count += i % 2, i /= 2);
    return count;
}
