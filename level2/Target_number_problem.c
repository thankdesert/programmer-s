/*
---------------------------------------------
Target_number_problem
from : https://programmers.co.kr/learn/courses/30/lessons/43165
solved by dfs(implemented by recursion)
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

int answer;
void check(int size, int target, int pos, int sum, vector<int>& numbers) {
    if(pos == size) {
        if(sum == target) {
            answer++;
            return;
        }
    }
    else {
        check(numbers.size(), target, pos + 1, sum + numbers[pos], numbers);
        check(numbers.size(), target, pos + 1, sum - numbers[pos], numbers);
    }
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    check(numbers.size(), target, 0, 0, numbers);
    return answer;
}
