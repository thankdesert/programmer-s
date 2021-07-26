/*
---------------------------------------------
The_long_jump_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12914
solved using by dynamic_programming.
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> v(n, 0);
    v[0] = 1;
    v[1] = 2;
    for(int i = 2; i< n; i++)
        v[i] = (v[i-2] + v[i-1])%1234567;

    return v[n-1]%1234567;
}
