/*
---------------------------------------------
simple(12933)
from : https://programmers.co.kr/learn/courses/30/lessons/12933
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string line = to_string(n);
    sort(line.rbegin(), line.rend());
    return stoll(line);
}
