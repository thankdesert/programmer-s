/*
---------------------------------------------
A_pair_of_bracket_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12909
---------------------------------------------
*/

#include <string>

using namespace std;

bool solution(string s) {
    int i, cnt_l = 0, cnt_r = 0;
    
    for(i = 0; i<s.size() && cnt_l >= cnt_r; i++)
        s[i] == '(' ? cnt_l++ : cnt_r++;
    
    return ((cnt_l + cnt_r) == s.size() && cnt_l == cnt_r) ? true : false;
}
