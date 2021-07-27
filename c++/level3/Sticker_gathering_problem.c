/*
---------------------------------------------
Sticker_gathering_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12971?language=cpp#
solved by using a dynamic_programming
---------------------------------------------
*/

#include <vector>
using namespace std;

int solution(vector<int> sticker) {
    int answer =0, i, max;
    vector<int> v(sticker.size());
    
    if(sticker.size() == 1)
        return sticker[0];
    
    v[0] = sticker[0];
    v[1] = sticker[0];
    for(i = 2; i<sticker.size()-1; i++)
        sticker[i] + v[i-2] > v[i-1] ? v[i] = sticker[i] + v[i-2] : v[i] = v[i-1];
    max = v[sticker.size()-2];
    
    for(i = 0; i<v.size(); i++)
        v[i] = 0;
    
    v[0] = 0;
    v[1] = sticker[1];
    for(i = 2; i<sticker.size(); i++)
        sticker[i] + v[i-2] > v[i-1] ? v[i] = sticker[i] + v[i-2] : v[i] = v[i-1];
    
    return max > v[i-1] ? max : v[i-1];
}
