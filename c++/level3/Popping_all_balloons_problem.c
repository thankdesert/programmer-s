/*
---------------------------------------------
Popping_all_balloons_problem
from : https://programmers.co.kr/learn/courses/30/lessons/68646
---------------------------------------------
*/


#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<int> a) {
    int i, answer = 2, min;
    vector<int> left_min(a.size(), 0);
    vector<int> right_min(a.size(), 0);
    
    min = INT_MAX;
    for(i = 0; i<a.size(); i++) {
        if(a[i] < min)
            min = a[i];
        left_min[i] = min;
    }
    
    min = INT_MAX;
    for(i = a.size()-1; i>=0; i--) {
        if(a[i] < min)
            min = a[i];
        right_min[i] = min;
    }
    
    for(i = 1; i<a.size() - 1; i++) {
        if(a[i] > left_min[i] && a[i] > right_min[i])
            continue;
        answer++;
    }
    
    return answer;
}
