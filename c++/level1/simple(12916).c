/*
---------------------------------------------
simple(12916)
from : https://programmers.co.kr/learn/courses/30/lessons/12916
---------------------------------------------
*/

#include <string>
using namespace std;

bool solution(string s) {
    bool answer = true;
    int cnt = 0;
    for(auto item : s) {
        if(toupper(item) == 'P')
            cnt++;
        else if(toupper(item) == 'Y')
            cnt--;
    }
    if(cnt != 0)
        answer = false;
    
    return answer;
}
