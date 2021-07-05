/*
---------------------------------------------
A_carpet_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42842
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int h, v, flag, total = brown + yellow;
    for(flag = 0, h = 1; h <= brown && flag == 0; h++)
        for(v = 1; v <= h; v++) {
            if((v-2)*(h-2) == yellow && v*h == total) {
                answer.push_back(h);
                answer.push_back(v);
                flag = 1;
                break;
            }
        }
    return answer;
}
