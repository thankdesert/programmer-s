/*
---------------------------------------------
Removing_all_duplicate_numbers_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12906
---------------------------------------------
*/

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}
