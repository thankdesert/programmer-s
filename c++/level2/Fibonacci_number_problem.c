/*
---------------------------------------------
Fibonacci_number_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12945?language=cpp#
solved by using dynamic programming
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0, i;
    vector<int> v = {0, 1};
    for(i = 0; i<n - 1; i++)
        v.push_back(v[i]%1234567 + v[i+1]%1234567);
    
    return v[n]%1234567;
}
