/*
---------------------------------------------
A_triangle_snail_problem
from : https://programmers.co.kr/learn/courses/30/lessons/68645
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int i, cur_num = 1, cur_length = n, cursor = 0, cur_level = 1, total = n*(n+1)/2, max_depth = (n-1)/3 + 1;
    for(i = 0; i<total; i++)
        answer.push_back(0);
    
    for(int cur_depth = 0; cur_depth < max_depth; cur_depth++) {
        for(i = 0; i< cur_length; i++, cursor += cur_level++)
            answer[cursor] = cur_num++;
        cursor -= --cur_level;
        cursor++;
        for(i = 0; i < cur_length - 1; cursor++, i++) {
            answer[cursor] = cur_num++;
        }
        cursor--;
        
        cursor -= cur_level--;
        for(i = 0; i < cur_length - 2; cursor -= cur_level--, i++) 
            answer[cursor] = cur_num++;
        cursor += (cur_level + 1)*2;
        cur_level += 2;
        cur_length -= 3;
    }
    return answer;
}
