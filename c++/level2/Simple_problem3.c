/*
---------------------------------------------
Simple_problem3
from : https://programmers.co.kr/learn/courses/30/lessons/12924#
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0, i, j, sum;
    
    for(i = 1;i<=n;i++) {
        sum = 0;
        for(j = i;sum < n;j++)
            sum += j;
        if(sum == n)
            answer++;
    }
    return answer;
}
