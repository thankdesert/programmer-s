/*
---------------------------------------------
Pick_two_and_sum_problem
from : https://programmers.co.kr/learn/courses/30/lessons/68644
solved by using set.
---------------------------------------------
*/

#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;
    int i, j, length;
    for(i = 0, length = numbers.size(); i<length; i++)
        for(j = i + 1; j<length; j++)
            s.insert(numbers[i]+numbers[j]);
    answer.assign(s.begin(), s.end());
    return answer;
}
