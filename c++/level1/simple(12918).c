/*
---------------------------------------------
simple(12918)
from : https://programmers.co.kr/learn/courses/30/lessons/12918
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if(s.size() != 4 && s.size() != 6)
        return false;
    for(auto item : s)
        if(!isdigit(item))
            return false;
    return true;
}
