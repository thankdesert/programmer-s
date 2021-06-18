/*
---------------------------------------------
The_124_country's_number
from : https://programmers.co.kr/learn/courses/30/lessons/12899
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> v;
    int x, t, cur = n;
    
    for(;;) {
        if(cur <= 3) {
            if(cur == 3)
                cur = 4;
            v.push_back(cur);
            break;
        }            
        else {
            if(cur % 3 == 0)
                x = (cur/3) - 1;
            else
                x = (cur/3);
            t = cur - x*3;
            if(t == 3)
                t = 4;
            v.push_back(t);
            cur = x;
        }            
    }
    
    for(int i = v.size() - 1; i >= 0; i--) {
        answer.push_back(v[i] + '0');
    }
    return answer;
}
