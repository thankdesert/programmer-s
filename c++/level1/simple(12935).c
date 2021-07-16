/*
---------------------------------------------
simple(12935)
from : https://programmers.co.kr/learn/courses/30/lessons/12935
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    arr.erase(min_element(arr.begin(), arr.end()));
    if(arr.size() == 0)
        arr.push_back(-1);
    return arr;
}
