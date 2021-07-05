/*
---------------------------------------------
The_Pohnkémon_problem
from : https://programmers.co.kr/learn/courses/30/lessons/1845
---------------------------------------------
*/


#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0, i, spc = 0;
    int s[200001] = {0};
    
    for(i = 0; i< nums.size(); i++) {
        if(s[nums[i]] == 0)
            spc++;
        s[nums[i]]++;
    }
    
    if(spc > (nums.size())/2)
        answer = (nums.size())/2;
    else
        answer = spc;
    
    return answer;
}
