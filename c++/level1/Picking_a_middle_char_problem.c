/*
---------------------------------------------
Picking_a_middle_char_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12903
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    return s.size()%2 ? s.substr(s.size()/2, 1) : s.substr(s.size()/2 - 1, 2);
}
