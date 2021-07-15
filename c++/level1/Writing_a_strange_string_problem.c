/*
---------------------------------------------
Writing_a_strange_string_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12930
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int l, r;
    for(l = 0; l < s.size() && r < s.size(); l = r + 1) {
        for(r = l; s[r] != ' ' && r<s.size(); r++) {
            if((r-l)%2 == 0 && s[r] >= 'a' && s[r] <= 'z')
                s[r] -= ('a'-'A');
            if((r-l)%2 == 1 && s[r] >= 'A' && s[r] <= 'Z')
                s[r] += ('a'-'A');
        }
    }
    return s;
}
