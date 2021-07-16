/*
---------------------------------------------
simple(12928)
from : https://programmers.co.kr/learn/courses/30/lessons/12928
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0, i;
    for(i = 1; i<=n; i++)
        if(n % i == 0)
            answer += i;
    return answer;
}
