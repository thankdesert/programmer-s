/*
---------------------------------------------
Kakao's_shopping_gems_problem.c
from : https://programmers.co.kr/learn/courses/30/lessons/67258
---------------------------------------------
*/

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int i, j, min, temp = 0, num = 0, cnt = 0, g_cnt = 0, size = gems.size();
    queue<string> q;
    unordered_map<string, int> um; //key, index
    for(i = 0; i<size; i++) {
        if(um[gems[i]] == 0)
            um[gems[i]] = 1;
    }
    num = um.size();
    um.clear();
    int left = 0, right = 100001;
    for(i = 0; i<size; i++) {
        if(um[gems[i]] == 0)
            um[gems[i]] = 1;
        else
            um[gems[i]] += 1;
        q.push(gems[i]);
        
        while(um[q.front()] > 1) {
            um[q.front()] -= 1;
            q.pop();
            temp++;
        }
        
        if(um.size() == num && right > q.size()) {
            right = q.size();
            left = temp;
            printf("%d ~ %d\n", left, left + right - 1);
        }
    }
    return {left + 1, left + right};
}
