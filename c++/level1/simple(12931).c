/*
---------------------------------------------
simple(12931)
from : https://programmers.co.kr/learn/courses/30/lessons/12931
---------------------------------------------
*/

#include <string>

using namespace std;
int solution(int n) {
    int answer = 0;
    string line = to_string(n);
    for(auto item : line)
        answer += item - '0';
    return answer;
}
