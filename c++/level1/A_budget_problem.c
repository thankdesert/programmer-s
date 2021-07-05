/*
---------------------------------------------
A_budget_problem.c
from : https://programmers.co.kr/learn/courses/30/lessons/12982
---------------------------------------------
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int i, sum;
    for(i = 0, sum = 0, sort(d.begin(), d.end()); i <d.size() && sum + d[i] <= budget; sum += d[i++]);
    return i;
}
