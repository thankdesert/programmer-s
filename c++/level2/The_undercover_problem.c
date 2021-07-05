/*
---------------------------------------------
The_undercover_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42578
solved by using unordered_map & combination.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1, i;
    unordered_map<string, int> um;
    for(i = 0; i< clothes.size(); i++)
        um[clothes[i][1]]++;
    
    for(auto elem : um)
        answer *= (elem.second + 1);
    
    return --answer;
}
