/*
---------------------------------------------
The_best_set_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12938
---------------------------------------------
*/


#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s/n == 0)
        return {-1};
    for(int i = 0; i<n; i++)
        answer.push_back(s/n);
    for(int i = 0; i<s%n; i++)
        answer[answer.size() - 1 - i] += 1;
    
    return answer;
}
