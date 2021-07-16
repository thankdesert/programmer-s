/*
---------------------------------------------
simple(12910)
from : https://programmers.co.kr/learn/courses/30/lessons/12910
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(auto item : arr)
        if(item % divisor == 0)
            answer.push_back(item);
    if(answer.size() == 0)
        answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}
