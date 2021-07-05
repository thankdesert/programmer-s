/*
---------------------------------------------
Writing_a_JadenCase_string_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12951
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer;
    int first = 1;
    for(int i = 0; i<s.size(); i++) {
        if(s[i] == ' ') {
            first = 1;
            answer.push_back(' ');
            continue;
        }
        
        if(first == 1) {
            if(s[i] >= 'a' && s[i] <= 'z')
                answer.push_back(s[i] - 32);
            else
                answer.push_back(s[i]);
            first = 0;
        } else {
            if(s[i] >= 'A' && s[i] <= 'Z')
                answer.push_back(s[i] + 32);
            else
                answer.push_back(s[i]);
        }
    }
    
    return answer;
}
