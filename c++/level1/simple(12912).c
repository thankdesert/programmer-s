/*
---------------------------------------------
simple(12912)
from : https://programmers.co.kr/learn/courses/30/lessons/12912
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0, l = a, r = b;
    if(a > b) {
        l = b;
        r = a;
    }
    for(;l<=r; l++)
        answer += l;
    return answer;
}
