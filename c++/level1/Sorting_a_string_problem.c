/*
---------------------------------------------
Sorting_a_string_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12915
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int p;
bool cmp(string a, string b) {
    return a[p] == b[p] ? a < b : a[p] < b[p];
}

vector<string> solution(vector<string> strings, int n) {
    p = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}
