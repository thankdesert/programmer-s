/*
---------------------------------------------
String_sort_problem
https://programmers.co.kr/learn/courses/30/lessons/12917
---------------------------------------------
*/

#include <string>
#include <algorithm>

using namespace std;

string solution(string s) {
    sort(s.rbegin(), s.rend());
    return s;
}
