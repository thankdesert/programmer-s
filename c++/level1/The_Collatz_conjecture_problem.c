/*
---------------------------------------------
The_Collatz_conjecture_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12943
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int cnt = 0, i;
    long long n = num;
    for(i = 0; i<500; i++) {
        if(n == 1)
            return cnt;
        n % 2 ? n = n * 3 + 1 : n /= 2;
        cnt++;
    }
    return -1;
}
